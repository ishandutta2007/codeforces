#include <iostream>
#include <string>
#include <map> 
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>


using namespace std;

#define sqr(x) ((x)*(x))
#define PB(a) push_back(a)
#define MP(a) make_pair(a)
#define ll long long

int gcd(int a, int b) {
	while (b) b^=a^=b^=a%=b;
	return a;
}

const int maxn = 5 * 100100;

int n, k;
string s;
int d[maxn][26];
pair<int, int> p[maxn][26];

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
	/*n = 500000;
    k = 26;
    s = "";
    for (int i = 0; i < n; i++)
        s += 'A'; */

    cin >> n >> k >> s;
	memset(d, 1e6, sizeof(d));
	d[0][0] = 0;
	d[0][1] = s[0] != 'A';
	d[0][2] = s[0] != 'B';
	d[0][3] = s[0] != 'C';
	for (int i = 0; i < (int)s.length() - 1; i++) {
		for (int cur = 0; cur < min(k + 1, 5); cur++) {
			char c;
			if (cur == 0) c = s[i];
			else c = (char)('A' + cur - 1);
			for (int nw = 0; nw < min(k + 1, 5); nw++) {
				char g;
				if (nw == 0) g = s[i + 1];
				else g = (char)('A' + nw - 1);
				if (c != g)
					if (d[i + 1][nw] > d[i][cur] + (g != s[i + 1])) {
						d[i + 1][nw] = d[i][cur] + (g != s[i + 1]);
						p[i + 1][nw] = make_pair(i, cur);
					}
			}
		}
	}

	int ans = 1e6, cur = -1;
	for (int i = 0; i < min(k + 1, 5); i++)
		if (ans > d[n - 1][i]) {
			ans = d[n - 1][i];
			cur = i;
		}

	cout << ans << endl;
	int u = n - 1;
	string str = "";
	while (u >= 0) {
		if (cur == 0) str += s[u];
		else str += (char)('A' + cur - 1);
		cur = p[u][cur].second;
		u--;
	}

	reverse(str.begin(), str.end());
	cout << str;

	return 0;
}