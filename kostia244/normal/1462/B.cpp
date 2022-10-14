#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 602, mod = 1e9 + 7;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		string s;
		cin >> s >> s;
		if(s.size() < 4) {
			cout << "NO\n";
			continue;
		}
		int ok = 0;
		ok |= s.substr(0, 4) == "2020";
		ok |= s.substr(s.size()-4, 4) == "2020";
		ok |= s.substr(0, 2) == "20" && s.substr(s.size()-2, 2) == "20";
		ok |= s.substr(0, 3) == "202" && s.substr(s.size()-1, 1) == "0";
		ok |= s.substr(0, 1) == "2" && s.substr(s.size()-3, 3) == "020";
		cout << (ok?"YES":"NO") << '\n';
	}
}