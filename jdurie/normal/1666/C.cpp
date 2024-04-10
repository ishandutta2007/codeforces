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

pl p[3];

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	for (ll i=0; i<3; ++i) cin>>p[i].K>>p[i].V;
	sort(all(p));
	ll best=LLONG_MAX;
	vector<vl> ans;
	do {
		ll cur = 0;
		vector<vl> s;

		cur += abs(p[0].K-p[1].K) + abs(p[0].V-p[1].V);	
		if (p[0].K!=p[1].K) s.push_back({p[0].K, p[0].V, p[1].K, p[0].V});
		if (p[0].V!=p[1].V) s.push_back({p[1].K, p[0].V, p[1].K, p[1].V});

		ll best1 = LLONG_MAX;
		vector<vl> s1;
		for(auto l : s){
			ll x1 = 0, y1 = 0;
			ll maxx = max(l[0], l[2]), mixx = min(l[0], l[2]), maxy = max(l[1], l[3]), mixy = min(l[1], l[3]);
			if(mixx <= p[2].K && p[2].K <= maxx) x1 = p[2].K;
		       	else if(p[2].K < mixx) x1 = mixx;
			else x1 = maxx;	
			if(mixy <= p[2].V && p[2].V <= maxy) y1 = p[2].V;
		       	else if(p[2].V < mixy) y1 = mixy;
			else y1 = maxy;
			ll cur1 = abs(x1-p[2].K) + abs(y1-p[2].V);
			if(cur1 < best1){
				best1 = cur1;
				s1.clear();
				if(x1 != p[2].K) s1.push_back({p[2].K, p[2].V, x1, p[2].V});
				if(y1 != p[2].V) s1.push_back({x1, p[2].V, x1, y1});
			}
		}
		cur += best1;
		s.insert(s.begin(), s1.begin(), s1.end());
		if (cur<best) {
			best = cur;
			ans = s;
		}
	} while(next_permutation(all(p)));

	cout<<ans.size()<<'\n';
	for (auto a:ans) {
		for (auto o:a) cout<<o<<' ';
		cout<<'\n';
	}
}