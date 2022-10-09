#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
string s;

int mv[3][3], cnt[3], tmp[3];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> s;
	for (int i=0; i<n; i++)
		cnt[s[i] - '0']++;

	int h = n / 3;

	copy(cnt, cnt+3, tmp);
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++) {
			int w = max(0, min(tmp[i] - h, h - tmp[j]));
			mv[i][j] = w;
			tmp[i] -= w;
			tmp[j] += w;
		}

	for (int i=0; i<3; i++)
		for (int j=0; j<i; j++)
			for (int k=0; k<n; k++)
				if (s[k] - '0' == i && mv[i][j] > 0) {
					mv[i][j]--;
					s[k] = '0' + j;
				}

	for (int i=0; i<3; i++)
		for (int j=2; j>i; j--)
			for (int k=n-1; k>=0; k--)
				if (s[k] - '0' == i && mv[i][j] > 0) {
					mv[i][j]--;
					s[k] = '0' + j;
				}
	cout << s << '\n';
}