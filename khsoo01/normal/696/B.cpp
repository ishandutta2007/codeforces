#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, chi[100005], par[100005];
double ans[100005];

vector<ll> cg[100005];

void calc (ll cur, ll prev) {
    chi[cur] = 1;
    for(ll i=0;i<cg[cur].size();i++) {
        if(cg[cur][i]==prev) continue;
        calc(cg[cur][i], cur);
        chi[cur] += chi[cg[cur][i]];
    }
}

int main()
{
    scanf("%lld",&n);
    for(ll i=2;i<=n;i++) {
        scanf("%lld",&par[i]);
        cg[i].push_back(par[i]);
        cg[par[i]].push_back(i);
    }
    calc(1, -1);
    ans[1] = 1;
    printf("%.9f ",ans[1]);
    for(ll i=2;i<=n;i++) {
        ans[i] = ans[par[i]] + 1 + (((double)(chi[par[i]]-chi[i]-1))/2);
        printf("%.9f ",ans[i]);
    }
}