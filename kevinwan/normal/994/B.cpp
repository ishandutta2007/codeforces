#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct k {
	ll p,c, in,ans=0;
};
struct idk {
	bool operator()(k a, k b) { return a.in < b.in; }
} les;
struct idek {
	bool operator()(k a, k b) { return a.p < b.p; }
} lesss;
k a[100000];
ll op[10];
int main() {
	int n,kk,i,j;
	scanf("%d%d", &n,&kk);
	for (i = 0; i < n; i++) {
		scanf("%lld", &a[i].p);
		a[i].in = i;
	}
	for (i = 0; i < n; i++)scanf("%lld", &a[i].c);
	sort(a, a + n,lesss);
	for (i = 0; i < n; i++) {
		a[i].ans += a[i].c;
		for (j = 0; j < kk; j++) {
			a[i].ans += op[j];
		}
		if (a[i].c > op[kk - 1]) {
			op[kk - 1] = a[i].c;
			for (j = kk - 2; j >= 0; j--) {
				if (op[j + 1] > op[j])op[j] ^= op[j + 1] ^= op[j] ^= op[j + 1];
				else break;
			}
		}
	}
	sort(a, a + n, les);
	for (i = 0; i < n; i++)printf("%lld ", a[i].ans);
	getchar(); getchar();
}