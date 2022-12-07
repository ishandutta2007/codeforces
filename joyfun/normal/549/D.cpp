#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define sz(x) (int)x.size()

const int N = 105;
int n, m;
char g[N][N];
int ad[N];

int main() {
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (int i = 1; i <= n; i++) scanf("%s", g[i] + 1);
	for (int i = n; i >= 1; i--) {
		int s = 0;
		for (int j = m; j >= 1; j--) {
			int x = g[i][j] == 'B' ? -1 : 1;
			ad[j] += s;
			if (ad[j] != x) {
				s += x - ad[j];
				ad[j] = x;
				ans++;
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}