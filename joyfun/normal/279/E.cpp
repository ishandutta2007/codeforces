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

const int N = 1000005;
char s[N];
int n;
int cnt[N][2];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '1') {
			int j = i;
			while (j <= n && s[j] == '1') j++;
			cnt[i][0]++;
			cnt[j][1]++;
			i = j - 1;
			ans += 2;
		}
	}
	for (int i = 1; i <= 1000000; i++) {
		int use = min(cnt[i][0], cnt[i - 1][1]);
		cnt[i - 1][1] -= use; cnt[i][0] -= use;
		ans -= use;
		use = min(cnt[i][0], cnt[i + 1][1]);
		ans -= use;
		cnt[i][0] -= use; cnt[i + 1][1] -= use;
	}
	printf("%d\n", ans);
	return 0;
}