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
	string s;
	cin >> s;
	int i = 0;
	while(i < s.size()) {
		if(s[i] == '.') {
			cout << 0;
			++i;
			continue;
		}
		if(s[i + 1] == '.') {
			cout << 1;
			i += 2;
			continue;
		}
		cout << 2;
		i += 2;
	}
}