#pragma GCC optimize("trapv")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,tune=native")
#include<bits/stdc++.h>
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vvi = vector<vi>;
using ld = long double;
const ll mod = 1e9 + 7, maxn = 3e5 + 55;
ll f[maxn], inv[maxn];
ll bp(ll a, ll p) {
	ll r = 1;
	while(p) {
		if(p&1) r = (r*1ll*a)%mod;
		a = (a*1ll*a)%mod, p>>=1;
	}
	return r;
}
void setup() {
	f[0] = inv[0] = 1;
	for(ll i = 1; i < maxn; i++) {
		f[i] = (f[i-1]*1ll*i)%mod;
	}
	inv[maxn-1] = bp(f[maxn-1], mod-2);
	for(ll i = maxn-1; i--;)
		inv[i] = (inv[i+1]*1ll*(i+1))%mod;
}
ll nck(ll n, ll k) {
	ll r = (f[n]*1ll*inv[k])%mod;
	return (r*1ll*inv[n-k])%mod;
}

struct state {
	ll s, c1, c2;
	state(ll s, ll c1, ll c2) : c1(c1), c2(c2), s(s) {
	}
};
queue<state> q;
pi merge(pi a, pi b) {
	if(a.first > b.first) swap(a, b);
	if(a.first==b.first) a.second += b.second;
	if(a.second>=mod) a.second -= mod;
	return a;
}
pi ans[55][55][55];
ll n, k, c1 = 0, c2 = 0;
#define M(x) ((x)%mod)
int32_t main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	setup();
	cin >> n >> k;
	for(ll t, i = 0; i < n; i++) {
		cin >> t;
		(t==50?c1:c2)++;
	}
	for(ll i = 0; i < 55; i++)
		for(ll j = 0; j < 55; j++)
			for(ll k = 0; k < 55; k++)
				ans[i][j][k] = {1ll<<50, 0};
	q.emplace(0, c1, c2);
	ans[c1][c2][0] = {0, 1};
	while(!q.empty()) {
		state st = q.front();
		q.pop();
//		cout << st.c1 << " " << st.c2 << " " << st.s << " " << ans[st.c1][st.c2][st.s].first << "\n";
		if(st.c1==0&&st.c2==0) {
			cout << ans[0][0][1].first << "\n";
			cout << ans[0][0][1].second << "\n";
			return 0;
		}
		ll cst = ans[st.c1][st.c2][st.s].first;
		ll now = ans[st.c1][st.c2][st.s].second;
		if(st.s) {
			for(ll a = 0; st.c1+a <= c1; a++)
				for(ll b = 0;st.c2+b <= c2; b++) {
					if(a+b<1||a*50 + b*100 > k) continue;
//					cout << a << " " << b << "\n";
			ans[st.c1+a][st.c2+b][0] = merge(ans[st.c1+a][st.c2+b][0], {cst+1, M(M(now*1ll*nck(c1-st.c1, a))*1ll*nck(c2-st.c2, b))});
			if(ans[st.c1+a][st.c2+b][0]==pi{cst+1, M(M(now*1ll*nck(c1-st.c1, a))*1ll*nck(c2-st.c2, b))})
				q.emplace(0, st.c1+a, st.c2+b);
			}
		} else {
			for(ll a = 0; a <= st.c1; a++)
				for(ll b = 0; b <= st.c2; b++) {
					if(a+b<1||a*50 + b*100 > k) continue;
//					cout << a << " " << b << "\n";
					ans[st.c1-a][st.c2-b][1] = merge(ans[st.c1-a][st.c2-b][1], {cst+1, M(M(now*1ll*nck(st.c1, a))*1ll*nck(st.c2, b))});
					if(ans[st.c1-a][st.c2-b][1]==pi{cst+1, M(M(now*1ll*nck(st.c1, a))*1ll*nck(st.c2, b))})
						q.emplace(1, st.c1-a, st.c2-b);
				}
		}
	}
	cout << "-1\n0";
}