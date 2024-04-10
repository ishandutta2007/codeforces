#include<cstdio>
#include<algorithm>
using namespace std;
int n, K, L = 4007;
long long T[4010], T2[4010], Mod = 998244353, Inv2 = Mod / 2 + 1, Inv4 = Inv2*Inv2%Mod, Len, RR[4010];
long long A[2010][4010], B[2010][4010], PA[3] = { 0,2,Mod-2 }, PB[3] = { 1,Mod-2,2 }, Comb[2020][2020];
long long Inv(long long a) {
	long long b = Mod - 2, r = 1;
	while (b) {
		if(b&1)r = r * a%Mod;
		a = a * a%Mod; b >>= 1;
	}
	return r;
}
int main() {
	int i, j, k;
	scanf("%d%d%lld", &n, &K, &Len);
	A[0][0] = 1;
	B[0][0] = 1;
	for (i = 0; i <= 2000; i++) {
		Comb[i][0] = 1;
		for (j = 1; j <= i; j++)Comb[i][j] = (Comb[i - 1][j - 1] + Comb[i - 1][j]) % Mod;
	}
	for (i = 1; i <= n+1; i++) {
		for (j = 0; j < 2 * i; j++) {
			for (k = 0; k < 3; k++) {
				A[i][j + k] = (A[i][j + k] + 1ll * A[i - 1][j] * PA[k]) % Mod;
				B[i][j + k] = (B[i][j + k] + 1ll * B[i - 1][j] * PB[k]) % Mod;
			}
		}
	}
	for (i = 0; i <= L; i++)T[i] = A[n][i];
	for (i = n; i >= K; i--) {
		for (j = 0; j <= L; j++) {
			RR[j] = (RR[j] + T[j] * Comb[n][i]) % Mod;
			T2[j] = 0;
		}
		for (j = L; j >= 0; j--) {
			if (T[j]) {
				long long t = T[j] * Inv2 % Mod;
				t = Mod - t;
				T2[j-2] = t;
				T[j] = (T[j] + 2 * t) % Mod;
				T[j - 1] = (T[j - 1] - 2 * t+Mod*2) % Mod;
			}
		}
		for (j = 0; j <= L; j++)T[j] = 0;
		for (j = 0; j <= L-2; j++) {
			for (k = 0; k < 3; k++) {
				T[j + k] = (T[j + k] + T2[j] * PB[k]) % Mod;
			}
		}
	}
	long long res = 0;
	for (i = 0; i <= L; i++) {
		res = (res + RR[i] * Inv(i + 1)) % Mod;
	}
	printf("%lld\n", res*Len%Mod);
}