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

const char str[6][6] = {"S", "M", "L", "XL", "XXL", "XXXL"};
int cnt[6];
map<string, int> to;
char s[105];
int ans[100005];
vi w[6];

int main() {
	for (int i = 0; i < 6; i++) to[str[i]] = i;
	for (int i = 0; i < 6; i++) scanf("%d", &cnt[i]);
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", s);
		int f = 0;
		for (int j = 0; s[j]; j++) if (s[j] == ',') {
			s[j] = 0;
			f = 1;
			break;
		}
		if (!f) cnt[to[s]]--, ans[i] = to[s];
		else w[to[s]].pb(i);
	}
	for (int i = 0; i < 6; i++) {
		if (cnt[i] < 0) {
			printf("NO\n");
			return 0;
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < sz(w[i]); j++) {
			if (cnt[i]) {
				ans[w[i][j]] = i;
				cnt[i]--;
			} else {
				if (cnt[i + 1]) {
					ans[w[i][j]] = i + 1;
					cnt[i + 1]--;
				} else {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	for (int i = 0; i < n; i++) printf("%s\n", str[ans[i]]);
	return 0;
}