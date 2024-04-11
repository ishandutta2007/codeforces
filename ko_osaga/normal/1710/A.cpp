#include <bits/stdc++.h>
#define sz(v) ((int)(v).size())
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long lint;
typedef pair<lint, lint> pi;

int a[1 << 20];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	while(t--){
		int n, m, k; cin >> n >> m >> k;
		vector<int> a(k);
		for(auto &x : a) cin >> x;
		auto solve = [&](vector<int>  &a, int n, int m){
			vector<int> v;
			for(auto &x : a){
				if(x >= 2ll * n){
					v.push_back(x / n);
				}
			}
			sort(all(v));
			reverse(all(v));
			lint lo = 0, hi = 0;
			for(auto &x : v){
				lo += 2;
				hi += x;
				if(lo <= m && m <= hi) return true;
			}
			return false;
		};
		if(solve(a, n, m) || solve(a, m, n)) cout << "Yes\n";
		else cout << "No\n";
	}
}