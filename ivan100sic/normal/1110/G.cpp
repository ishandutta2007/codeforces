#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 33;

int n;
basic_string<int> e[500005];
bool dp[500005][H], found;
int dub[500005];
string s;

/*
0: .

1: O

2: . -- .

3: . -- O

4: O -- .

5: O -- O

6: . -- . -- .

7: . -- . -- O

8: . -- O -- .

9: . -- O -- O

10: O -- . -- .

11: O -- . -- O

12: O -- O -- .

13: O -- O -- O

14: . -- .
    |
    |
    .

15: . -- O
    |
    |
    .

16: . -- O
    |
    |
    O

17: O -- .
    |
    |
    .

18: O -- O
    |
    |
    .

19: O -- O
    |
    |
    O

20: neki (ne nuzno root) izomorfizam sa . -- O -- . -- .
	nema dalje

21: . -- . -- .
    |
    |
    . -- .

22: . -- . -- .
	|
	|
	.

23: . -- (22)

24: spajder

25: O -(x3)- .

26: . -- (17)

27: O -- . -- .
         |
         |
         .

28: . -(x2)- .
    |
    |
    O

29: . -- . -- O
         |
         |
         .

30: . -(x3)- .

31: . -(x4)- .

32: . -- (30)
    |
    |
    .

*/

void dfs(int x, int p) {
	vector<int> tipovi(H, 0);

	for (int y : e[x]) {
		if (y == p)
			continue;
		dub[y] = dub[x] + 1;
		dfs(y, x);
		for (int i=0; i<H; i++)
			if (dp[y][i])
				tipovi[i]++;
	}

	auto d = dp[x];

	d[0] = true;
	d[1] = s[x] == 'W';

	d[2] = tipovi[0] >= 1;
	d[3] = tipovi[1] >= 1;
	d[4] = tipovi[0] >= 1 && s[x] == 'W';
	d[5] = tipovi[1] >= 1 && s[x] == 'W';

	d[6] = tipovi[2] >= 1;
	d[7] = tipovi[3] >= 1;
	d[8] = tipovi[4] >= 1;
	d[9] = tipovi[5] >= 1;

	d[10] = tipovi[2] >= 1 && s[x] == 'W';
	d[11] = tipovi[3] >= 1 && s[x] == 'W';
	d[12] = tipovi[4] >= 1 && s[x] == 'W';
	d[13] = tipovi[5] >= 1 && s[x] == 'W';

	d[14] = tipovi[0] >= 2;
	d[15] = tipovi[0] >= 2 && tipovi[1] >= 1;
	d[16] = tipovi[1] >= 2;

	d[17] = tipovi[0] >= 2 && s[x] == 'W';
	d[18] = tipovi[0] >= 2 && tipovi[1] >= 1 && s[x] == 'W';
	d[19] = tipovi[1] >= 2 && s[x] == 'W';

	d[20] = tipovi[8] >= 1 || tipovi[10] >= 1 ||
		(tipovi[0] >= 2 && tipovi[2] >= 1 && s[x] == 'W') ||
		(tipovi[0] >= 2 && tipovi[4] >= 1);

	d[21] = tipovi[2] >= 2;
	d[22] = tipovi[2] >= 1 && tipovi[0] >= 2;
	d[23] = tipovi[22] >= 1;

	d[24] = tipovi[21] >= 1 || (tipovi[22] >= 1 && tipovi[0] >= 2) ||
		(tipovi[2] >= 2 && tipovi[0] >= 3) || (tipovi[23] >= 1);

	d[25] = tipovi[0] >= 3 && s[x] == 'W';
	d[26] = tipovi[17] >= 1;

	d[27] = tipovi[14] >= 1 && s[x] == 'W';
	d[28] = tipovi[0] >= 3 && tipovi[1] >= 1;
	d[29] = tipovi[15] >= 1;

	d[30] = tipovi[0] >= 3;

	d[31] = tipovi[0] >= 4;
	d[32] = tipovi[30] >= 1;

	found |= d[24] || d[9] || d[11] || d[12] || d[13] ||
		d[16] || d[18] || d[19] || d[20] || d[25] || d[26] ||
		d[27] || d[28] || d[29] || d[31] || d[32];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	for (int tc=0; tc<t; tc++) {

		cin >> n;
		for (int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}

		basic_string<int> racve;
		for (int i=1; i<=n; i++)
			if (e[i].size() >= 3)
				racve += i;

		cin >> s;
		s = string(" ") + s;

		dfs(1, 1);

		// if (t == 40000 && tc == 448 && count(s.begin(), s.end(), 'W')) {
		// 	for (int i=1; i<=n; i++)
		// 		for (int x : e[i])
		// 			if (x < i)
		// 				cout << x << i << "_";
		// 	cout << s.substr(1) << '\n';
		// 	return 0;
		// }

		basic_string<int> wpos;

		for (int i=1; i<=n; i++)
			if (s[i] == 'W')
				wpos += i;
		if (wpos.size() >= 3)
			found = true;
		else if (wpos.size() == 2) {
			int x = wpos[0];
			int y = wpos[1];
			if ((dub[x] + dub[y]) % 2 == 0) {
				found = true;
			}
		}

		set<int> parnosti_racve, parnosti_wpos;
		for (int x : wpos)
			parnosti_wpos.insert(dub[x] % 2);
		for (int x : racve)
			parnosti_racve.insert(dub[x] % 2);

		for (int x : parnosti_racve)
			for (int y : parnosti_wpos)
				if (x != y)
					found = true;

		if (racve.size() >= 3) {
			found = true;
		} else if (racve.size() == 2) {
			int x = racve[0];
			int y = racve[1];

			if ((dub[x] + dub[y]) % 2 == 0)
				found = true;
		}
		cout << (found ? "White\n" : "Draw\n");

		for (int i=1; i<=n; i++) {
			fill(dp[i], dp[i]+H, 0);
			e[i] = {};
			dub[i] = 0;
		}
		found = 0;
	}
}