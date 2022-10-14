#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;

#define F(i, l, r) for(ll i = l; i < (r); i++)
#define G(x) ll x; cin >> x;

#define NN 200010
ll a[NN], b[NN], goesto[NN], ass[NN], wait[NN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	// pos, avail, idx fors sort, idx
	typedef tuple<ll, ll, ll, ll> car;
	// tim, 0, idx of req
	// tim, 1, idx of car becmoing vail
	typedef tuple<ll, ll, ll> ev;
	#define g0 get<0>
	#define g1 get<1>
	#define g2 get<2>
	#define g3 get<3>
	#define tim get<0>
	#define typ get<1>
	#define idx get<2>
	
	priority_queue<ev, vector<ev>, greater<ev>> events;
	queue<ev> reqs;
	set<car> nex, prev;

//	{x, -2}, {x, -1} || s
	#define inscar(x, t, i) {nex.insert({x, t, i, i}); prev.insert({x, -t, -i, i});}
	
	ll n, k, m;
	cin>>n>>k>>m;
	for (ll i=1; i<=k; ++i) {
		ll x;
		cin>>x;
		inscar(x, 0, i)
	}
	for (ll i=0; i<m; ++i) {
		ll t;
		cin>>t>>a[i]>>b[i];
		events.push({t, 0, i});
	}
	while (!events.empty()) {
		ll o = tim(events.top());
		while (events.empty()==0 && o==tim(events.top())) {
			auto e = events.top();
			events.pop();
			if (typ(e)==0) {
				reqs.push(e);
			} else {
				inscar(goesto[idx(e)], o, idx(e));
			}
		}

		while (! (reqs.empty() || nex.empty())) {
			auto r = reqs.front();
			reqs.pop();
			ll s = a[idx(r)];
			car best = {LLONG_MAX, 0, 0, 0};
			auto nw = nex.lower_bound({s, -1, -1, -1});
			if (nw!=nex.end()) {
				best = min(best, car{abs(g0(*nw)-s), g1(*nw), g2(*nw), g0(*nw)});
			}
			auto pw = prev.lower_bound({s, LLONG_MAX, LLONG_MAX, LLONG_MAX});
			if (pw != prev.begin()) {
				pw--;
				best = min(best, car{abs(g0(*pw)-s), -g1(*pw), -g2(*pw), g0(*pw)});
			}
			// x t  i i 
			nex.erase({g3(best), g1(best), g2(best), g2(best)});
			prev.erase({g3(best), -g1(best), -g2(best), g2(best)});

			ass[idx(r)] = g2(best);
			wait[idx(r)] = o - tim(r) + g0(best);
			goesto[g2(best)] = b[idx(r)];
			ll reach = o + g0(best) + abs(a[idx(r)] - b[idx(r)]);
			events.push({reach, 1, g2(best)});
		}
	}
	for (ll i=0; i<m; ++i) cout<<ass[i]<<' '<<wait[i]<<'\n';
}