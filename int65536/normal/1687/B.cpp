#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <bits/stdc++.h>

using namespace std;

using ll = long long;
#define FOR(i, s, t) for (int i = static_cast<int>(s); i < static_cast<int>(t); ++i)
#define REP(i, n) for (int i = 0; i < static_cast<int>(n); ++i)

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	vector<pair<int, int>> a(m);
	REP(i, m) {
		string s(m, '0');
		s[i] = '1';
		printf("? %s\n", s.c_str());
		fflush(stdout);
		int val;
		scanf("%d", &val);
		a[i] = { val,i };
	}
	sort(a.begin(), a.end());
	int ret = 0;
	int last = 0;
	string cur(m, '0');
	for (const auto& edge : a) {
		cur[edge.second] = '1';
		printf("? %s\n", cur.c_str());
		fflush(stdout);
		int val;
		scanf("%d", &val);
		if (val == last + edge.first) {
			ret += edge.first;
			last = val;
		}
		else {
			cur[edge.second] = '0';

		}
	}
	printf("! %d\n", ret);
	fflush(stdout);
	return 0;
}