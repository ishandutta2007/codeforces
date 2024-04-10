#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
const int maxnm=300*300+5;
int n,m;
struct node{
    int id,v;
}a[maxnm],b[maxnm];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')y=-1;ch=getchar();}
    while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
bool cmp1(node i,node j){return i.v==j.v?i.id>j.id:i.v<j.v;}
priority_queue<pair<int,int> >q;
void solve(int l,int r){
    int rt=(r-1)/m+1,lt=(l-1)/m+1;
    if(lt==rt)return ;
    int k=r-((r-1)/m)*m;
    for(int i=l;i<=r;i++)q.push(make_pair(a[i].id,a[i].v));
    int pos=((r-1)/m)*m;
    while(k--){b[++pos]=(node){q.top().fi,q.top().se};q.pop();}
    for(int i=rt-1;i>=lt;i--){
        int cur=m;
        pos=max((i-1)*m,l-1);
        while(cur--&&q.size()){b[++pos]=(node){q.top().fi,q.top().se};q.pop();}
    }
    for(int i=l;i<=r;i++)a[i]=b[i];
    return ;
}
int main(){
    int T;
    T=read();
    while(T--){
        n=read();m=read();
        int s=n*m;
        for(int i=1;i<=s;i++)a[i]=(node){i,read()};
        sort(a+1,a+n*m+1,cmp1);
        int pre=1;
        for(int i=1;i<=s;i++)if(i>1&&a[i].v>a[i-1].v)solve(pre,i-1),pre=i;
        solve(pre,s);
        int res=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                for(int k=1;k<j;k++)
                    if(a[(i-1)*m+k].id<a[(i-1)*m+j].id)res++;
        printf("%d\n",res);
    }
    return 0;
}