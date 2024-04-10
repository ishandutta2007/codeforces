#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, k, sum[200005], dep[200005], ans;
vector<ll>cg[200005];

void calc (ll cur, ll prev, ll cdep) {
    if(sum[cur]) ans += cdep;
    dep[cur] = cdep;
    for(ll i=0;i<cg[cur].size();i++) {
        if(cg[cur][i] == prev) continue;
        calc(cg[cur][i], cur, cdep+1);
        sum[cur] += sum[cg[cur][i]];
    }
}

void solve (ll cur, ll prev, ll mat) {
    ll mxv = 0, mxi = -1;
    for(ll i=0;i<cg[cur].size();i++) {
        if(cg[cur][i] == prev) continue;
        if(sum[cg[cur][i]]>mxv) {
            mxv = sum[cg[cur][i]];
            mxi = cg[cur][i];
        }
    }
    if(2*mxv-sum[cur]-mat<=0) {
        ans -= (sum[cur]-mat)*dep[cur];
        return;
    }
    ans -= 2*(sum[cur]-mxv)*cur[dep];
    solve(mxi, cur, mat+sum[cur]-mxv);
}

int main()
{
    scanf("%lld%lld",&n,&k);
    for(int i=0;i<2*k;i++) {
        ll tmp;
        scanf("%lld",&tmp);
        sum[tmp] += 1;
    }
    for(int i=1;i<n;i++) {
        ll A, B;
        scanf("%lld%lld",&A,&B);
        cg[A].push_back(B);
        cg[B].push_back(A);
    }
    calc(1, -1, 0);
    solve(1, -1, 0);
    printf("%lld\n",ans);
}