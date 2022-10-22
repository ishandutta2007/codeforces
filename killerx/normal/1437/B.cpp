#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mp make_pair
#define pb push_back

#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

int calc(const string &s) {
	int n = s.size();
	int ans = 0;
	rep(i, n - 1) ans += s[i] == s[i + 1];
	return (ans + 1) / 2;
}

int main() {
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int ans = calc(s);
		cout << ans << endl;
	}
	return 0;
}