#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 1000010;
const int MOD = 1000000007;

int n, m, l;
int pos[MAXN];
char s[MAXN];

int f[MAXN];
bool tag[MAXN];

void Get_fail() {
	f[0] = f[1] = 0;
	for(int i = 1; i < l; i ++) {
		int j = f[i];
		for(; j && s[i] != s[j]; j = f[j]) ;
		f[i + 1] = s[i] == s[j] ? j + 1 : 0;
	}
	tag[l] = true;
	for(int i = f[l]; i; i = f[i]) tag[i] = true;
}

int Qpow(int a, int b) {
	int ans = 1;
	for(; b; b >>= 1, a = a * 1ll * a % MOD)
		if(b & 1) ans = ans * 1ll * a % MOD;
	return ans;
}

int main() {
	scanf("%d%d%s", &n, &m, s);
	l = strlen(s);
	Get_fail();
	for(int i = 1; i <= m; ++ i) {
		scanf("%d", &pos[i]);
		-- pos[i];
	}
	for(int i = 1; i <= m; ++ i) {
		if(pos[i] + l > n) return puts("0"), 0;
		if(i > 1 && pos[i - 1] + l > pos[i]) {
			int x = pos[i - 1] + l - pos[i];
			if(!tag[x]) return puts("0"), 0;
		}
	}
	int len = 0, L = 0, R = -1;
	for(int i = 1; i <= m; ++ i) {
		if(i > 1 && pos[i - 1] + l > pos[i]) R = pos[i] + l - 1;
		else {
			len += R - L + 1;
			L = pos[i], R = pos[i] + l - 1;
		}
	}
	len += R - L + 1;
	printf("%d\n", Qpow(26, n - len));
	return 0;
}