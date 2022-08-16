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
		int type = -1, n, m; cin >> n >> m;
		bool error = false;
		for(int i = 0; i < n; i++){
			string s; cin >> s;
			for(int j = 0; j < m; j++){
				if(s[j] != '.'){
					int c = s[j] == 'R';
					int tt = c ^ ((i + j) % 2);
					if(type == -1) type = tt;
					else if(type != tt){
						error = true;
					}
				}
			}
		}
		if(type == -1) type = 0;
		if(error){
			cout << "NO" << endl;
			continue;
		}
		cout << "YES\n";
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cout << ((((i + j) % 2) ^ type) ? 'R' : 'W');
			}
			cout << endl;
		}
	}
}