#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second
#define N 200100

int a[N];
struct seg {
	pair<int,int> *comp;
	int n, st;
	int *t;
	
	void init1(int nn, int tt, pair<ll, int>*cmm) {
		n = nn;
		st = tt;
		comp = new pair<int, int>[n];
		for (int i=0; i<n; ++i) comp[i]={a[cmm[i+st].V], cmm[i+st].V};
		t = new int[2*n];
		fill(t, t+2*n, INT_MIN/10);
	}

	void init2(int nn, pair<int, int>* comp1, pair<int, int>*comp2) {
		n = nn;
		comp = new pair<int, int>[n];
		merge(comp1, comp1+n/2, comp2, comp2+n/2, comp);
		t = new int[2*n];
		fill(t, t+2*n, INT_MIN/10);
	}

	void modify(int p, int v) {
		p = lower_bound(comp, comp+n, pair<int, int>{a[p], p})-comp;
		p+=n;
		while (p>0) {
			t[p] = max(t[p], v);
			p/=2;
		}
	}

	int query(int l, int r) {
		l = lower_bound(comp, comp+n, pair<int,int>{l, -1})-comp;
		r = lower_bound(comp, comp+n, pair<int, int>{r, -1})-comp;
		int res = INT_MIN/10;
		for (l+=n, r+=n; l<r; l/=2, r/=2) {
			if (l&1) res = max(res, t[l++]);
			if (r&1) res = max(res, t[--r]);
		}
		return res;
	}

	// modify and query
};

ll t[N];
int dp[N];
ll vu[N], vb[N];

struct s {
	pair<ll, int> *comp;
	int n;
	seg *t;
	ll *d;
	vector<pair<int, int>> rang;
	void init(int nn, ll *c) {
		n = nn;
		d = c;
		comp = new pair<ll, int>[n];
		for (int i=0; i<n; ++i) comp[i]={c[i],i};
		sort(comp, comp+n);
		t = new seg[2*n];
		rang.resize(2*n);

		for (int p=2*n-1; p>0; --p) {
			if (p>=n) rang[p] = {p-n, p-n};
			else rang[p] = {rang[p*2].K, rang[p*2+1].V};

			if (p>=n) t[p].init1(1, rang[p].K, comp);
			else if (rang[p*2].V-rang[p*2].K==rang[p*2+1].V-rang[p*2+1].K) t[p].init2(rang[p].V-rang[p].K+1, t[2*p].comp, t[2*p+1].comp);
		}
	}

	void modify(int i, int v) {
		ll p = lower_bound(comp, comp+n, pair<ll,int>{d[i], i})-comp;
		p+=n;
		while (p>0) {
			if(p>=n || rang[p*2].V-rang[p*2].K==rang[p*2+1].V-rang[p*2+1].K) t[p].modify(i, v);
			p/=2;
		}
	}

	int query(ll l1, ll r1, int l2,int r2) {
		l1 = lower_bound(comp, comp+n, pair<ll,int>{l1, -1})-comp;
		r1 = lower_bound(comp, comp+n, pair<ll,int>{r1, -1})-comp;

		int res = INT_MIN/10;
		for (l1+=n, r1+=n; l1<r1; l1/=2, r1/=2) {
			if (l1&1) res = max(res, t[l1++].query(l2, r2));
			if (r1&1) res = max(res, t[--r1].query(l2, r2));
		}
		return res;
	}
};

s pos, neg;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	G(n) G(v)
	F(i, 1, n+1) cin >> t[i];
	F(i, 1, n+1) cin >> a[i];
	dp[0] = 0;
	int ans = 0;
	F(i, 1, n+1){
		vu[i] = v*t[i]+a[i];
		vb[i] = v*t[i]-a[i];
	}
	pos.init(n+1, vu);
	neg.init(n+1, vb);
	neg.modify(0, 0);
	pos.modify(0, 0);
	F(i, 1, n+1){
		dp[i] = neg.query(LLONG_MIN, vb[i]+1, INT_MIN, a[i]+1);
		dp[i] = max(dp[i], pos.query(LLONG_MIN, vu[i]+1, a[i], INT_MAX));
		dp[i]++;
		ans = max(ans, dp[i]);
		neg.modify(i, dp[i]);
		pos.modify(i, dp[i]);
	}
	cout << ans << "\n";
}