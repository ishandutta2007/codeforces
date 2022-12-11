#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define pb push_back

typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef double db;

int k, ff[11000];

int f(int u) {
	if(u < 0) return 1;
	if(~ ff[u]) return ff[u];
	return ff[u] = !(f(u - 1) && f(u - 2) && f(u - k));
}
const char *s3 = "BAAA";
const char *s6 = "BAABAAA";
const char *s9 = "BAABAABAAA";
const char *s = "BAA";

int main() {
	int t; scanf("%d", &t);
	while(t --) {
		int n;
		scanf("%d%d", &n, &k);
//		fill(ff, ff + n + 1, -1);
		if(k == 3 && 0) {
			puts(s3[n % (k + 1)] == 'A' ? "Alice" : "Bob");
		} else if(k == 6&& 0) {
			puts(s6[n % (k + 1)] == 'A' ? "Alice" : "Bob");
		} else if(k == 9&& 0) {
			puts(s9[n % (k + 1)] == 'A' ? "Alice" : "Bob");
		} else if(k % 3 == 0) {
			int x = n % (k + 1);
			if(x % 3 == 0 && x != k) puts("Bob");
			else puts("Alice");
		} else {
			puts(s[n % 3] == 'A' ? "Alice" : "Bob");
		}
		
//		for(int i = 0; i <= n; i ++) {
//			printf("f[%d][%d] = %d\n", i, k, f(i));
//		}
	}
	return 0;
}