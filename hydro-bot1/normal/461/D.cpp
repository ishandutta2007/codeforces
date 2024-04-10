// Hydro submission #628cb89937e0de7afd368ac1@1653389465686
#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
const int N = 1e5 + 5;
int Pa[N << 1], n, m, a, b;
char ch;
void Merge(int x, int y);
int Find(int x);
int qpow(int x, int k);
int main() {
	int T1, T2;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n + n + 4; i++) {
		Pa[i] = i;
	}
	for (int i = 1; i <= m; i++) {
		scanf("%d%d", &a, &b);
		ch = getchar();
		while (ch != 'o' && ch != 'x') {
			ch = getchar();
		}
		T1 = abs(a - b) + 1;
		if (a + b - 1 > n) {
			T2 = n - (a - (n - b)) + 1;
		} else {
			T2 = a + b - 1;
		}
		T2 += 2;
		if (ch == 'o') {
			if (Find(T1) == Find(T2) || Find(T1 + n + 2) == Find(T2 + n + 2)) {
				printf("0");
				return 0;
			}
			Merge(T1, T2 + n + 2);
			Merge(T1 + n + 2, T2);
		} else {
			if (Find(T1) == Find(T2 + n + 2) || Find(T1 + n + 2) == Find(T2)) {
				printf("0");
				return 0;
			}
			Merge(T1, T2);
			Merge(T1 + n + 2, T2 + n + 2);
		}
	}
	T1 = 0;
	for (int i = 1; i <= n + n + 4; i++) {
		if (Find(i) == i) {
			T1++;
		}
	}
	T1 = T1 / 2 - 2;
	printf("%d", qpow(2, T1));
	return 0;
}
void Merge(int x, int y) {
	x = Find(x);
	y = Find(y);
	if (x == y) {
		return;
	}
	Pa[x] = y;
	return;
}
int Find(int x) {
	if (Pa[x] == x) {
		return x;
	}
	return Pa[x] = Find(Pa[x]);
}
int qpow(int x, int k) {
	int Ans = 1;
	for (int i = k; i; i >>= 1, x = 1ll * x * x % mod) {
		if (i & 1) {
			Ans = 1ll * Ans * x % mod;
		}
	}
	return Ans;
}