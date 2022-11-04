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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int i = 0;
		int am = 0;
		while(i < n - 1) {
			if(s[i] == '(') {
				++am;
				i += 2;
				continue;
			}
			int j = i + 1;
			while(j < n && s[j] != ')') ++j;
			if(j == n) break;
			++am;
			i = j + 1;
		}
		cout << am << ' ' << n - i << '\n';
	}
}