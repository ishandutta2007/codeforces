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
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		string s; cin >> s;
		for(int i = 0; i < m; i++){
			string s2 = s;
			for(int j = 0; j < n; j++) if(s2[j] == '0'){
				int k = 0;
				if(j > 0 && s2[j - 1] == '1') k^=1;
				if(j + 1 < n && s2[j + 1] == '1') k^=1;
				if(k) s[j] = '1';
			}
			if(s2 == s) break;
		}
		cout << s << endl;
	}
}