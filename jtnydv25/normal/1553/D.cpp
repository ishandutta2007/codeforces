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
	int q; cin >> q;
	while(q--){
		string s, t;
		cin >> s;
		cin >> t;
		bool ok = false;
		int n = s.length(), m = t.length();
		for(int u = 0; u < 2; u++){
			int p = u, q = 0, pos = 0;
			for(int i = 0; i < n; i++){
				if(q < m && i % 2 == p && s[i] == t[q]){
					p^=1;
					q++;
					pos = i;
				}
			}
			if(q == m && (n - 1 - pos) % 2 == 0){
				ok = true;
				break;
			}
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}