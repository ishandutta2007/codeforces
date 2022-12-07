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

const int N = 5005;
const int inf = 0x3f3f3f3f;
int n, a[N], ma[N][N];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) if (a[i] > a[j]) cnt++;
	int ans = cnt, tot = 1;
	for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++)
			ma[i][j] = ma[i][j - 1] + (a[i] < a[j]);
	for (int i = n; i >= 1; i--)
		for (int j = i - 1; j >= 1; j--)
			ma[i][j] = ma[i][j + 1] + (a[i] > a[j]);
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			int aa = ma[i][j - 1], bb = ma[j][i + 1];
			int tmp = cnt + aa - (j - i - 1 - aa) + bb - (j - i - 1 - bb);
			tmp += (a[i] < a[j] ? 1 : -1);
			if (ans > tmp) {
				ans = tmp;
				tot = 1;
			} else if (ans == tmp) tot++;
		}
	}
	printf("%d %d\n", ans, tot);
	return 0;
}