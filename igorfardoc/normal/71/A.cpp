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
		if(s.size() > 10) {
			string t = "";
			t += s.back();
			int a = s.size() - 2;
			while(a) {
				int here = a % 10;
				t += (char)('0' + here);
				a /= 10;
			}
			t += s[0];
			reverse(t.begin(), t.end());
			s = t;
		}
		cout << s << '\n';
	}
}