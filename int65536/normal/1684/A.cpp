#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

char solve(string s)
{
	int n = s.size();
	if (n == 1) return s[0];
	if (n == 2) return s[1];
	sort(s.begin(), s.end());
	return s[0];
}
int main()
{
#ifdef _MSC_VER
	freopen("a.in", "r", stdin);
#endif
	std::ios::sync_with_stdio(false);
	int n_cases;
	cin >> n_cases;
	for (int case_id = 0; case_id < n_cases; case_id++)
	{
		string s;
		cin >> s;
		printf("%c\n", solve(s));
	}
	return 0;
}