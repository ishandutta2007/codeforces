#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back
#define fs first
#define sc second
#define ucin() ios :: sync_with_stdio(0)

typedef map<int, int> mii;
typedef vector<int> vi;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

const int N = 1e6 + 10;
const int mo1 = 19260817;
const int mo2 = 18940417;
const int ba = 9781;

int tot, h1[N], h2[N], yh1[N], yh2[N], n, st[N], len[N], pw1[N], pw2[N];
char s[N], ans[N];

void pushchar(char c) {
	ans[++ tot] = c;
	h1[tot] = (1ll * h1[tot - 1] * ba + c) % mo1;
	h2[tot] = (1ll * h2[tot - 1] * ba + c) % mo2;
}
int ghash1(int l, int r) {
	return ((h1[r] - 1ll * h1[l - 1] * pw1[r - l + 1] % mo1) % mo1 + mo1) % mo1;
}
int ghash2(int l, int r) {
	return ((h2[r] - 1ll * h2[l - 1] * pw2[r - l + 1] % mo2) % mo2 + mo2) % mo2;
}
int yghash1(int l, int r) {
	return ((yh1[r] - 1ll * yh1[l - 1] * pw1[r - l + 1] % mo1) % mo1 + mo1) % mo1;
}
int yghash2(int l, int r) {
	return ((yh2[r] - 1ll * yh2[l - 1] * pw2[r - l + 1] % mo2) % mo2 + mo2) % mo2;
}
int prek1(int u, int k) { return yghash1(st[u], st[u] + k - 1); }
int prek2(int u, int k) { return yghash2(st[u], st[u] + k - 1); }

bool issame(int l, int r, int u, int k) {
	if(ghash1(l, r) != prek1(u, k)) return 0;
	return ghash2(l, r) == prek2(u, k);
}

int main() {
	pw1[0] = pw2[0] = 1;
	for(int i = 1; i < N; i ++) {
		pw1[i] = 1ll * pw1[i - 1] * ba % mo1;
		pw2[i] = 1ll * pw2[i - 1] * ba % mo2;
	}
	scanf("%d", &n);
	int pos = 1;
	for(int i = 1; i <= n; i ++) {
		st[i] = pos;
		scanf("%s", s + st[i]);
		len[i] = strlen(s + st[i]);
		pos += len[i];
	}
	pos --;
	for(int i = 1; i <= pos; i ++) {
		yh1[i] = (1ll * yh1[i - 1] * ba + s[i]) % mo1;
		yh2[i] = (1ll * yh2[i - 1] * ba + s[i]) % mo2;
	}
	for(int i = 1; i <= n; i ++) {
		if(i == 1) {
			for(int j = 1; j <= len[1]; j ++) pushchar(s[j]);
			continue ;
		}
		int r = min(tot, len[i]), ans = 0, mid;
		for(int mid = r; mid >= 1; mid --) {
			if(issame(tot - mid + 1, tot, i, mid)) {
				ans = mid; break ;
			}
		}
		for(int j = st[i] + ans; j < st[i] + len[i]; j ++) pushchar(s[j]);
	}
	ans[tot + 1] = 0; puts(ans + 1);
	return 0;
}