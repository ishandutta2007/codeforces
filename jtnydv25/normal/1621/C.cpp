#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#define endl '\n'
#endif

struct Judge{
    // variables
	int n;
	vector<int> q, p, _q, _p;
    Judge(){
        // code for given input
		cin >> n;
		p.resize(n + 1); q.resize(n + 1); _q.resize(n + 1), _p.resize(n + 1);
		iota(all(q), 0);
        #ifdef LOCAL
        // code for generating hidden input
		for(int i = 1; i <= n; i++) p[i] = i;
		random_shuffle(p.begin() + 1, p.end());
        #endif
    }

    int query(int i){
        #ifdef LOCAL
        // local judge implementation
		int ret = q[i];
		for(int i = 1; i <= n; i++) _q[i] = q[p[i]];
		q = _q;
		return ret;
        #endif
		cout << "? " << i << endl;
		fflush(stdout);
		int u; cin >> u;
		return u;
    }

    void solve(){
		vector<int> vis(n + 1);
		for(int i = 1; i <= n; i++) if(!vis[i]){
			int j = i;
			int h = query(j);
			while(!vis[h]){
				vis[h] = true;
				int _h = query(j);
				_p[h] = _h;
				h = _h;
			}
		}
		#ifdef LOCAL
		if(_p != p){
			trace(p, _p);
			assert(0);
		} else trace("ALL GOOD!");
		#endif
		cout << "! ";
		for(int i = 1; i <= n; i++) cout << _p[i] << " ";
		cout << endl;
		fflush(stdout);
    }
};



int main(){
	int t; cin >> t;
	while(t--){
    	Judge J;
    	J.solve();
	}
}