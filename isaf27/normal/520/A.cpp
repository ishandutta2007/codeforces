#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;
	string s;
	cin >> n >> s;
	for (int i = 0; i < n; i++)
		if ('A' <= s[i] && s[i] <= 'Z')
			s[i] += 'a' - 'A';
	vector<bool> used(26, false);
	for (int i = 0; i < n; i++)
		used[s[i] - 'a'] = true;
	bool ch = true;
	for (int i = 0; i < 26; i++)
		ch &= used[i];
	cout << (ch ? "YES" : "NO");
	return 0;
}