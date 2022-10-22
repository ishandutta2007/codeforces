#include<bits/stdc++.h>
#define int long long
#define ll long long
using namespace std;
const int maxn=3e5+5;
int n,m,X;
int a[maxn];
map<ll,int>id;
vector<int>to[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct que{
    int id,data;
    bool operator <(que i)const{return data<i.data;}
};
priority_queue<que>q;
bool vis[maxn];
int f[maxn];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
vector<int>s[maxn];
signed main(){
    n=read();m=read();X=read();
    int p=0;
    ll sum=0;
    for(int i=1;i<=n;i++){
        a[i]=read();
        sum+=a[i];
    }
    if(sum<1ll*(n-1)*X){puts("NO");return 0;}
    for(int i=1;i<=m;i++){
        int u,v;
        u=read();v=read();
        id[1ll*u*(n+1)+v]=id[1ll*v*(n+1)+u]=i;
        to[u].push_back(v);
        to[v].push_back(u);
    }
    for(int i=1;i<=n;i++)q.push((que){i,a[i]}),f[i]=i,s[i].push_back(i);
    puts("YES");
    while(!q.empty()){
        int k=q.top().id,u,data=q.top().data;
        q.pop();
        if(find(k)!=k||a[k]!=data)continue;
        int v=0,z=0;
        for(int i=0;i<s[k].size();i++){
            int x=s[k][i];
            for(int j=0;j<to[x].size();j++){
                int y=to[x][j];
                if(find(y)==k){swap(to[x][j],to[x][to[x].size()-1]),to[x].pop_back();j--;continue;}
                u=x;z=y;
                break;
            }
            if(!z){swap(s[k][i],s[k][s[k].size()-1]);s[k].pop_back();i--;continue;}
            v=find(z);break;
        }
        if(!z)return 0;
        if(s[k].size()<s[v].size())swap(k,v);
        for(int i=0;i<s[v].size();i++)s[k].push_back(s[v][i]);
        printf("%d\n",id[1ll*u*(n+1)+z]);
        f[v]=k;a[k]+=a[v]-X;
        q.push((que){k,a[k]});
    }
    return 0;
}