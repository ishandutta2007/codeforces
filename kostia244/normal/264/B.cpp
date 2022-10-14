#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define xx first.first
#define yy first.second
#define __V vector
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define mod 998244353ll
using namespace __gnu_pbds;
using namespace std;
void doin() {
	cin.tie();
	cout.tie();
	ios::sync_with_stdio(0);
//#ifdef LOCAL
//	freopen("input.txt", "r", stdin);
//#endif
}
typedef long long ll;
typedef double ld;
typedef pair<ll, ll> pi;
typedef pair<ld, ld> pd;
typedef map<int, int> mii;
typedef __V <int> vi;
typedef __V <pi> vpi;
typedef __V <__V<int>> vvi;
typedef __V <__V<pi>> vvpi;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll t, tt, ans = 0, n, lp[100005], dp[100005];
vi a, pr;
map<int, int> cnt;
vi divs;
int main() {
	doin();
	for(ll i = 2; i <= 100000; i++) {
        if(lp[i] == 0)
            lp[i] = i, pr.pb(i);
        for(ll j = 0; j < pr.size() && pr[j]*i <= 100000 && pr[j]<=lp[i]; j++)
            lp[i*pr[j]] = pr[j];
	}
	cin >> n;
	memset(dp, 0, sizeof dp);
	while(n--) {
        cin >> t;
        tt = t;
        divs.clear();
        while(t != 1) {
            while(lp[t] == lp[t/lp[t]])
                t/=lp[t];
            divs.pb(lp[t]);
            t/=lp[t];
        }
        ll mx = 0;
        for(int i = 0; i < divs.size(); i++)
            mx = max(mx, dp[divs[i]]);
        mx++;
        ans = max(ans, mx);
        for(int i = 0; i < divs.size(); i++)
            dp[divs[i]] = max(dp[divs[i]], mx);
    }
    cout << ans;
}