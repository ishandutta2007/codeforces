#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace __gnu_pbds;
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const int maxn = 2e5 + 55, mod = 1e9 + 7;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll pw[maxn];
//#define int ll
struct node {
	ll mn, mx, sm, cnt, ans;
	void add(ll xp) {//add edge
		xp%=mod;
		(mn += xp)%=mod, (mx += xp)%=mod;
		(ans = ans + sm*xp + ((cnt*xp)%mod)*xp)%=mod;
		(sm += xp*2ll*cnt)%=mod;
	}
};
node merge(node l, node r, ll d) {
	l.add((4ll*pw[d])%mod);
	r.add((7ll*pw[d])%mod);
//	cout << l.mn << " " << r.mn << "\n";
	node t;
//	cout << l.ans << " " << r.ans << "aa\n";
	t.mn = l.mn, t.mx = r.mx, (t.cnt = l.cnt+r.cnt+1)%=mod, (t.sm = l.sm + r.sm + l.mx+r.mn)%=mod, (t.ans = l.ans+r.ans+ l.mx*r.mn)%=mod;
//	cout << t.mn << " " << t.mx << " " << t.ans << "bb\n";
	return t;
}
string l, r;
map<pair<int, int>, node> dp;
node get(int d, int s) {
	if(d==l.size()) {
		node x;
		x.mx=x.mn=x.cnt=x.sm=x.ans=0;
//		cout << d << " " << s << " " << x.ans << "state\n";
		return x;
	}
	if(dp.count({d, s})) return dp[{d, s}];
	if(s==3) {
		if(l[d]==r[d]) {
			if(l[d]=='4') {
				node t = get(d+1, 3);
				t.add((4ll*pw[l.size()-1-d])%mod);
				return dp[{d, s}] = t;
			}
			node t = get(d+1, 3);
			t.add((7ll*pw[l.size()-1-d])%mod);
			return dp[{d, s}] = t;
		}
		node a, b;
		a = get(d+1, 1), b = get(d+1, 2);
		return dp[{d, s}] = merge(a, b, l.size()-d-1);
	}
	if(s==1) {
		if(l[d]=='4') {
			node a = get(d+1, 1);
			node b = get(d+1, 0);
			return dp[{d, s}] = merge(a, b, l.size()-d-1);
		}
		node a = get(d+1, 1);
		a.add((7ll*pw[l.size()-1-d])%mod);
		return dp[{d, s}] = a;
	}
	if(s==2) {
		if(r[d]=='7') {
			node a = get(d+1, 2);
			node b = get(d+1, 0);
			return dp[{d, s}] = merge(b, a, l.size()-d-1);
		}
		node a = get(d+1, 2);
		a.add((4ll*pw[l.size()-1-d])%mod);
		return dp[{d, s}] = a;
	}
	return dp[{d, s}] = merge(get(d+1, 0), get(d+1, 0), l.size()-d-1);
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	pw[0] = 1;
	for(int i = 1; i < maxn; i++) pw[i] = (pw[i-1]*10ll)%mod;
	cin >> l >> r;
	node t = get(0, 3);
	cout << t.ans << "\n";
}