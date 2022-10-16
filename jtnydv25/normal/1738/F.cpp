#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
// #define endl '\n' // remove in interactive
#endif

int get(int i){
	cout << "? " << i + 1 << endl;
	fflush(stdout);
	int x; cin >> x;
	return x - 1;
}

struct dsu{
	int n;
	vector<int> par;
	dsu(int n) : n(n), par(n){
		iota(par.begin(), par.end(), 0);
	}
	int root(int x){
		return x == par[x] ? x : (par[x] = root(par[x]));
	}
	bool merge(int x, int y){
		x = root(x); y = root(y);
		if(x == y) return 0;
		par[x] = y;
		return 1;
	}
};

int main(){
	// ios_base::sync_with_stdio(false); 
	// cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> d(n);
		for(int i = 0; i < n; i++) cin >> d[i];
		vector<int> perm(n);
		iota(all(perm), 0);
		sort(all(perm), [&](int i, int j){return d[i] > d[j];});
		vector<int> done(n);
		dsu D(n);
		for(int v: perm) if(!done[v]){
			done[v] = 1;
			for(int j = 0; j < d[v]; j++){
				int x = get(v);
				D.merge(x, v);
				if(done[x]){
					break;
				}
				done[x] = 1;
			}
		}
		cout << "! ";
		for(int i = 0; i < n; i++) cout << D.root(i) + 1 << " ";
		cout << endl;
		fflush(stdout);
	}
}