#include <bits/stdc++.h>
using namespace std;

#define N 1000005
#define ll long long

int n;
int a[N];
int mx[N][20], mn[N][20], leng[N];
int lst[N];

int getmx(int l, int r) {return max(mx[l][leng[r - l]], mx[r - (1 << leng[r - l])][leng[r - l]]);}
int getmn(int l, int r) {return min(mn[l][leng[r - l]], mn[r - (1 << leng[r - l])][leng[r - l]]);}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; ++ i) scanf("%d", &a[i]);
	for (int i = 2; i <= n; ++ i) leng[i] = leng[i / 2] + 1;
	for (int i = 0; i < n; ++ i) mx[i][0] = mn[i][0] = a[i];
	for (int j = 1; j < 20; ++ j) for (int i = 0; i + (1 << j) <= n; ++ i) {
		mx[i][j] = max(mx[i][j - 1], mx[i + (1 << (j - 1))][j - 1]);
		mn[i][j] = min(mn[i][j - 1], mn[i + (1 << (j - 1))][j - 1]);
	}
	ll ans = 0;
	memset(lst, -1, sizeof(lst));
	for (int i = 0; i < n; ++ i) {
		int lb, rb;
		lb = lst[a[i]] + 1, rb = i;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (getmx(md, i + 1) > a[i]) lb = md + 1;
			else rb = md;
		}
		int L = lb;
		lb = i, rb = n - 1;
		while (lb < rb) {
			int md = (lb + rb + 1) >> 1;
			if (getmx(i, md + 1) > a[i]) rb = md - 1;
			else lb = md;
		}
		int R = lb;
		ans += 1ll * (i - L + 1) * (R - i + 1) * a[i];
		lst[a[i]] = i;
	}
	memset(lst, -1, sizeof(lst));
	for (int i = 0; i < n; ++ i) {
		int lb, rb;
		lb = lst[a[i]] + 1, rb = i;
		while (lb < rb) {
			int md = (lb + rb) >> 1;
			if (getmn(md, i + 1) < a[i]) lb = md + 1;
			else rb = md;
		}
		int L = lb;
		lb = i, rb = n - 1;
		while (lb < rb) {
			int md = (lb + rb + 1) >> 1;
			if (getmn(i, md + 1) < a[i]) rb = md - 1;
			else lb = md;
		}
		int R = lb;
		ans -= 1ll * (i - L + 1) * (R - i + 1) * a[i];
		lst[a[i]] = i;
	}
	printf("%lld\n", ans);
	return 0;
}