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
		vi am(26);
		for(int i = 0; i < s.size(); i++) {
			am[s[i] - 'a']++;
		}
		bool ok = false;
		for(int i = 0; i < s.size(); i++) {
			--am[s[i] - 'a'];
			if(am[s[i] - 'a'] == 0) {
				for(int j = i; j < s.size(); j++) {
					cout << s[j];
				
				}
				cout << '\n';
				break;
			}
		}
	}
}