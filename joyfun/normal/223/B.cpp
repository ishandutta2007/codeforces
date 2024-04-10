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

const int N = 200005;
char a[N], b[N];
int n, m, pr[N], sf[N];

int cnt[N][26];

int main() {
	scanf("%s%s", a + 1, b + 1);
	n = strlen(a + 1); m = strlen(b + 1);
	int j = 1;
	memset(pr, -1, sizeof(pr));
	memset(sf, -1, sizeof(sf));
	pr[0] = 0; sf[m + 1] = n + 1;
	for (int i = 1; i <= m; i++) {
		while (j <= n && a[j] != b[i]) j++;
		if (j > n) break;
		pr[i] = j++;
	}
	j = n;
	for (int i = m; i >= 1; i--) {
		while (j >= 1 && a[j] != b[i]) j--;
		if (j < 1) break;
		sf[i] = j--;
	}
	for (int i = 1; i <= m; i++) {
		int c = b[i] - 'a';
		if (pr[i - 1] == -1 || sf[i + 1] == -1) continue;
		cnt[pr[i - 1] + 1][c]++;
		cnt[sf[i + 1]][c]--;;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < 26; j++) cnt[i][j] += cnt[i - 1][j];
		int c = a[i] - 'a';
		if (cnt[i][c] == 0) {
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
	return 0;
}