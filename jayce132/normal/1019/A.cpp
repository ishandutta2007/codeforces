#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<map>
#include<stack>
#include<vector>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int N=3e3+20;
const ll Inf=1ll<<60;

template<class T> void chkmax(T &a,T b) { a<b?a=b:0; };
template<class T> void chkmin(T &a,T b) { a>b?a=b:0; };
int n,m,w[N];
vector<int> v[N],vn;
bool vis[N];
bool cmp(int a,int b) {
    return w[a]<w[b];
}
ll calc(int x) {
    ll ret=0;
    int cnt=v[1].size();
    memset(vis,0,sizeof(vis));
    for(int i=2;i<m || i==m;i++)
        for(int j=0;j<(int)v[i].size()-x+1;j++) ret+=w[v[i][j]],vis[v[i][j]]=1,cnt++;
    vector<int> vn;
    for(int i=2;i<=m;i++)
        for(int j=0;j<(int)v[i].size();j++) if(!vis[v[i][j]]) vn.push_back(v[i][j]);
    sort(vn.begin(),vn.end(),cmp);
    for(int i=0;i<(int)vn.size()&& !(cnt>=x);i++) ret+=w[vn[i]],cnt++;
    if(cnt<x) return Inf;
    else return ret;
}
int main() {
#ifndef ONLINE_JUDGE
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
#endif
    cin>>n>>m;
    for(int i=1;!(i>n);i++) v[read()].push_back(i),w[i]=read();
    for(int i=1;!(i>m);i++) sort(v[i].begin(),v[i].end(),cmp);
    ll ans=Inf;
    for(int i=1;i<n || i==n;i=i*4,i/=2,i/=2,i++) ans=min(ans,calc(i));
    printf("%lld\n",ans);
    return 0;
}