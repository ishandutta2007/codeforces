#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair <ll, ll> pll;
const ll mod1 = 1e9 + 7;
const ll mod2 = 1e9 + 9;
const int maxn = 6e5 + 10;
int n, m;
char str[maxn];
ll pow1[maxn], pow2[maxn];

set <pll> s;

ll hash1(char* str) {
	ll res = 0;
	for (int i = 0; i < strlen(str); i++) {
		res = ((res << 1) + res + str[i] - 'a') % mod1;
	}
	return res;
}

ll hash2(char* str) {
	ll res = 0;
	for (int i = 0; i < strlen(str); i++) {
		res = ((res << 1) + res + str[i] - 'a') % mod2;
	}
	return res;
}

int main() {
	pow1[0] = pow2[0] = 1;
	for (int i = 1; i <= 6e5; i++) {
		pow1[i] = ((pow1[i - 1] << 1) + pow1[i - 1]) % mod1;
		pow2[i] = ((pow2[i - 1] << 1) + pow2[i - 1]) % mod2;
	}
	scanf("%d %d", &n, &m);
	gets(str);
	for (int i = 1; i <= n; i++) {
		gets(str);
		int len = strlen(str);
		ll t1 = hash1(str), t2 = hash2(str);
		for (int j = 0; j < len; j++) {
			for (int k = 'a'; k <= 'c'; k++) {
				if (k != str[j]) {
					s.insert(make_pair((t1 + (pow1[len - j - 1] * (k - str[j])) + (mod1 << 1) + mod1) % mod1, (t2 + (pow2[len - j - 1] * (k - str[j])) + (mod2 << 1) + mod2) % mod2));
				}
			}
		}
	}
	for (; m--; ) {
		gets(str);
		puts(s.count(make_pair(hash1(str), hash2(str))) ? "YES" : "NO");
	}
	return 0;
}