#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,a[100005],mn[100005],sum[100005],chi[100005],ans;

vector<ll>cg[100005],cv[100005];

void calc(ll cur, ll prev) {
    chi[cur] = 1;
    for(ll i=0;i<cg[cur].size();i++) {
        if(cg[cur][i]!=prev) {
            calc(cg[cur][i],cur);
            chi[cur] += chi[cg[cur][i]];
        }
    }
}

void solve(ll cur, ll prev) {
    if(a[cur]<sum[cur]-mn[cur]) {
        ans += chi[cur];
        return;
    }
    for(ll i=0;i<cg[cur].size();i++) {
        if(cg[cur][i]!=prev) {
            sum[cg[cur][i]] = sum[cur] + cv[cur][i];
            mn[cg[cur][i]] = min(mn[cur], sum[cg[cur][i]]);
            solve(cg[cur][i],cur);
        }
    }
}

int main()
{
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++) scanf("%lld",&a[i]);
    for(ll i=2;i<=n;i++) {
        ll A,B;
        scanf("%lld%lld",&A,&B);
        cg[i].push_back(A);
        cv[i].push_back(B);
        cg[A].push_back(i);
        cv[A].push_back(B);
    }
    calc(1,-1);
    solve(1,-1);
    printf("%lld",ans);
}