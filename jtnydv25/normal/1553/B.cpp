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
		string s, t; cin >> s >> t;
		int n = s.length(), m = t.length();
		bool ok = false;
		for(int i = 0; i < n; i++){
			for(int j = 1; j <= m && i + j <= n; j++){
				int k = i + j - 1;
				if(j + k < m || s.substr(i, j) != t.substr(0, j)) continue;
				bool ok2 = true;
				// if(s=="abcdef" && i==2) trace(j);
				for(int r = j, p = k - 1; r < m; r++, p--){
					// if(s=="abcdef" && i==2) trace(r, p, s[p], t[r]);
					if(t[r] != s[p]){
						ok2 = false;
						break;
					}
				}
				if(ok2){
					cout << "YES\n";
					ok = true;
					break;
				}
			}
			if(ok) break;
		}
		if(!ok) cout << "NO\n";
	}
}