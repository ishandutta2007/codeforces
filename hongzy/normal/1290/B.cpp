#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
#include <queue>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int N = 2e5 + 10;
int cnt[N][26], n;
char s[N];
int main() {
	// freopen("input", "r", stdin);
	scanf("%s", s + 1); n = strlen(s + 1);
	for(int i = 1; i <= n; i ++) {
		for(int j = 0; j < 26; j ++) {
			cnt[i][j] = cnt[i - 1][j] + (s[i] - 'a' == j);
		}
	}
	scanf("%d", &n);
	for(int i = 1; i <= n; i ++) {
		int l, r; scanf("%d%d", &l, &r);
		int o = 0;
		for(int j = 0; j < 26; j ++) {
			if(cnt[r][j] ^ cnt[l - 1][j]) {
				o ++;
			}
		}
		bool tag = l == r;
		if(o >= 2) {
			if(s[l] ^ s[r]) tag = 1;
			else if(o > 2) tag = 1;
		}
		puts(tag ? "Yes" : "No");
	}
	return 0;
}