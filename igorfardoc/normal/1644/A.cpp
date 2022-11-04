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
		set<char> s1;
		bool ok = true;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] > 'a' && s[i] < 'z') {
				s1.insert(s[i]);
				continue;
			}
			s[i] = s[i] - 'A' + 'a';
			if(s1.find(s[i]) == s1.end()) {
				ok = false;
				break;
			}
		}
		if(ok) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}