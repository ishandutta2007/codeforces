#include <algorithm>
#include <cstring>
#include <cstdio>
#include <map>
using namespace std;

#define mp make_pair

typedef pair<int, int> pii;

const int N = 6e5 + 10;
const int B = 13;
const int mo = 998244353;
const int mo2 = 19260817;

int n, m, pw[N];
map<pii, bool> Map;
char s[N];

int ghash(char *s, int m) {
	int l = strlen(s), res = 0;
	for(int i = 0; i < l; i ++) {
		(res += pw[i] * 1ll * (s[i] - 'a' + 1) % m) %= m;
	}
	return res;
}

int modify(int h, int k, char s, char t, int m) {
	(h -= pw[k] * 1ll * (s - 'a' + 1) % m) %= m;
	h = (h + m) % m;
	(h += pw[k] * 1ll * (t - 'a' + 1) % m) %= m;
	return h;
}

int main() {
	pw[0] = 1;
	for(int i = 1; i < N; i ++) {
		pw[i] = pw[i - 1] * 1ll * B % mo;
	}
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i ++) {
		scanf("%s", s);
		pii x = mp(ghash(s, mo), ghash(s, mo2));
		Map[x] = 1;
	}
	for(int i = 1; i <= m; i ++) {
		scanf("%s", s);
		int l = strlen(s), h1 = ghash(s, mo), h2 = ghash(s, mo2);
		bool tag = 0;
		for(int j = 0; j < l; j ++) {
			for(char k = 'a'; k <= 'c'; k ++) if(k != s[j]) {
				pii x = mp(modify(h1, j, s[j], k, mo), modify(h2, j, s[j], k, mo2));
				if(Map[x]) {
					tag = 1; break ;
				}
			}
			if(tag) break ;
		}
		puts(tag ? "YES" : "NO");
	}
	return 0;
}