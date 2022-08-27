#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
#include<queue>
#include<map>
using namespace std;
#define mo 1000000007
#include<map>
typedef long long ll;
int qp(int a,ll b){
    int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;
}
#define inf 10000000000000000ll
ll f[222222][2];
int a[222222];
int n;
int pre[222222];
vector<int> ch[222222];

ll g[222222][2];
inline void upd(ll &a,ll b,ll c){
    if(b==-inf || c==-inf)return;
    a=max(a,b+c);
}
void dp(int u){
    g[0][0]=0;
    g[0][1]=-inf;
    for (int i=0;i<ch[u].size();i++){
        g[i+1][0]=g[i+1][1]=-inf;   
        upd(g[i+1][0],g[i][0],f[ch[u][i]][0]);
        upd(g[i+1][0],g[i][1],f[ch[u][i]][1]);
        upd(g[i+1][1],g[i][0],f[ch[u][i]][1]);
        upd(g[i+1][1],g[i][1],f[ch[u][i]][0]);
    }
    f[u][0]=g[ch[u].size()][0];
    f[u][1]=g[ch[u].size()][1];
    f[u][1]=max(f[u][1],a[u]+f[u][0]);
}
int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d%d",&pre[i],&a[i]);
    for (int i=2;i<=n;i++)ch[pre[i]].push_back(i);
    for (int i=n;i>=1;i--)dp(i);
    ll su=max(f[1][0],f[1][1]);
    cout<<su<<endl;
    return 0;
}