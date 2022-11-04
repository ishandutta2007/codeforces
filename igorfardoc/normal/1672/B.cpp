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
		int am = 0;
		bool ok = true;
		for(int i = 0; i < s.size(); i++) {
			if(s[i] == 'A') {
				++am;
			} else {
				--am;
				if(am < 0) {
					ok = false;
					break;
				}
			}
		}
		if(s.back() == 'A' || !ok) {
			cout << "NO\n";
		} else {
			cout << "YES\n";
		}
	}
}