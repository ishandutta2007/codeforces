#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, a[100005], sum[100005];
multiset<ll, greater<ll> > val;
set<ll> ep;

int main()
{
    scanf("%lld",&n);
    for(int i=1;i<=n;i++) {
        scanf("%lld",&a[i]);
        sum[i] = sum[i-1] + a[i];
    }
    val.insert(sum[n]);
    ep.insert(0); ep.insert(n);
    for(int i=1;i<=n;i++) {
        ll tmp;
        scanf("%lld",&tmp);
        auto it = ep.lower_bound(tmp);
        auto prv = it; prv--;
        ll S = (*prv)+1, E = *it;
        val.erase(val.find(sum[E]-sum[S-1]));
        val.insert(sum[tmp-1]-sum[S-1]);
        val.insert(sum[E]-sum[tmp]);
        ep.insert(tmp); ep.insert(tmp-1);
        printf("%lld\n",*(val.begin()));
    }
}