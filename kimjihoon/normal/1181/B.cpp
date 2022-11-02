#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct bi
{
	string s;
	string operator+(const bi &r) {
		string t = "";
		int pr = 0;
		for (int i = 0; i < max(s.length(), r.s.length()); i++) {
			int si = (int)s.length() - i - 1, ri = (int)r.s.length() - i - 1;
			int p = pr; pr = 0;
			if (ri >= 0) p += r.s[ri] - '0';
			if (si >= 0) p += s[si] - '0';
			t += (char)(p % 10 + '0');
			pr = p / 10;
		}
		if (pr) t += (char)(pr + '0');
		reverse(t.begin(), t.end());
		return t;
	}
	bool operator<(const bi &r) {
		if (s.length() != r.s.length()) return s.length() < r.s.length();
		for (int i = 0; i < s.length(); i++)
			if (s[i] != r.s[i]) return s[i] < r.s[i];
		return false;
	}
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n; cin >> n;
	string s; cin >> s;
	bi ans; ans.s = "";
	int ml = 1000000000;
	for (int i = 1; i < n; i++)
		if (s[i] != '0') 
			ml = min(ml, max(i, n - i) + 1);
	for (int i = 1; i < n; i++) {
		if (max(i, n - i) <= ml && s[i] != '0') {
			bi s1, s2; s1.s = s2.s = "";
			for (int j = 0; j < s.length(); j++) {
				if (j < i) s1.s += s[j];
				else s2.s += s[j];
			}
			bi t; t.s = s1 + s2;
			if (ans.s == "" || t < ans)
				ans.s = t.s;
		}
	}
	cout << ans.s << '\n';
	return 0;
}