#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		string s; cin >> s;
		vector<vector<int>> P(n + 1, vector<int>(3));
		for(int i = 1; i <= n; i++){
			int u = s[i - 1] - 'a';
			P[i] = P[i - 1];
			P[i][u]++;
		}
		int ans = 8;
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n && j <= i + 6; j++){
				int as = P[j][0] - P[i - 1][0];
				int bs = P[j][1] - P[i - 1][1];
				int cs = P[j][2] - P[i - 1][2];
				if(as > bs && as > cs) ans = min(ans, j - i + 1);
			}
		}
		cout << (ans == 8 ? -1 : ans) << endl;
	}
}