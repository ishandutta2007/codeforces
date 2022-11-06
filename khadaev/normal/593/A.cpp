#include <bits/stdc++.h>
using namespace std;

int count(string s, char c) {
	int ans = 0;
	for (char i : s)
		if (i == c) ++ans;
	return ans;
}

int main() {
	int n, ans = 0;
	cin >> n;
	string s[100];
	for(int i = 0; i < n; ++i) cin >> s[i];
	for (char a = 'a'; a <= 'z'; ++a)
		for (char b = a + 1; b <= 'z'; ++b) {
			int cnt = 0;
			for (int i = 0; i < n; ++i)
				if (count(s[i],a) + count(s[i],b) == s[i].size())
					cnt += s[i].size();
			ans = max(ans, cnt);
		}
	cout << ans << endl;
}