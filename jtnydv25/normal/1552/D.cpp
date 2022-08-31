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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int & x : a) cin >> x;
		bool ok = 0;
		for(int i = 1; i < (1 << n); i++){
			for(int j = 0; j < (1 << n); j++){
				int s = 0;
				for(int k = 0; k < n; k++){
					if(i >> k & 1){
						if(j >> k & 1) s -= a[k];
						else s += a[k];
					}
				}
				if(s == 0 && !ok){
					// trace(i, j);
					ok = 1;
				}
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}