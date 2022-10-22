#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxn=1e5+5;
int f1[maxn],f2[maxn];
set<pair<int,int> >R;
set<int>::iterator it;
set<int>r[maxn],c[maxn];
unordered_map<int,int>id[maxn];
pair<int,int>res[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int find1(int x){return x==f1[x]?x:f1[x]=find1(f1[x]);}
int find2(int x){return x==f2[x]?x:f2[x]=find2(f2[x]);}
void merge1(int x,int y){
    for(it=r[x].begin();it!=r[x].end();it++){
        int v=*it;
        r[y].insert(v);id[y][v]=id[x][v];
        c[v].erase(x),c[v].insert(y);
    }
    return ;
}
void merge2(int x,int y){
    for(it=c[x].begin();it!=c[x].end();it++){
        int v=*it;
        c[y].insert(v);id[v][y]=id[v][x];
        r[v].erase(x),r[v].insert(y);
    }
    return ;
}
int main(){
    int n,m1,m2;
    n=read();m1=read();m2=read();
    for(int i=1;i<=n;i++)f1[i]=f2[i]=i;
    for(int i=1;i<=m1;i++){
        int u,v;
        u=find1(read()),v=find1(read());
        f1[u]=v;
    }
    for(int i=1;i<=m2;i++){
        int u,v;
        u=find2(read()),v=find2(read());
        f2[u]=v;
    }
    if(m1<m2)swap(f1,f2);
    for(int i=1;i<=n;i++){
        int u=find1(i),v=find2(i);
        id[u][v]=i;
        r[u].insert(v);
        c[v].insert(u);
    }
    for(int i=1;i<=n;i++)if(i==find1(i))R.insert(make_pair(-r[i].size(),i));
    int len=0;
    while(R.size()>1){
        int x=(*R.begin()).se;R.erase(R.begin());
        int y=(*R.begin()).se;R.erase(R.begin());
        if(r[x].size()<r[y].size())swap(x,y);
        it=r[x].begin();
        int u=*r[x].begin(),v=*r[y].begin();
        if(u==v)u=*(++it);
        res[++len]=make_pair(id[x][u],id[y][v]);
        if(c[u].size()<c[v].size())swap(u,v);
        merge1(y,x);
        merge2(v,u);
        R.insert(make_pair(-r[x].size(),x));
    }
    printf("%d\n",len);
    for(int i=1;i<=len;i++)printf("%d %d\n",res[i].fi,res[i].se);
    return 0;
}