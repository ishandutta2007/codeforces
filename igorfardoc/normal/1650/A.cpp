#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<long long> vl;



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	#ifdef _FILE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s;
		char c;
		cin >> c;
		bool ok = false;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] != c) continue;
			if(i % 2 == 0) ok = true;
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}