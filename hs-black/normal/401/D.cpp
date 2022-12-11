#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int N = (1 << 18) + 5;
ll n, k, a[20], f[N][105];
ll len;
char s[200]; 
ll cnt[200], jie[300];
int main() {
	jie[0] = 1;
	for (int i = 1;i <= 19; i++) jie[i] = jie[i-1] * i;
	scanf ("%s%lld", s + 1, &k);
	len = strlen(s + 1);
	for (int i = 1;i <= len; i++) {
		a[i] = s[i] - '0';
		cnt[a[i]]++;
	}
	f[0][0] = 1;
	for (int i = 0;i < (1 << len) - 1; i++) {
		bool t = 0;
		for (int j = 1;j <= len; j++) {
			if ((i & (1 << (j - 1))) && s[j] != '0') {
				t = 1; break;
			}
		}
		if (!t && i) continue;	
		for (int j = 1;j <= len; j++) {
			if (i & (1 << (j-1))) continue;
			for  (int v = 0;v < k; v++) 
				f[i | (1 << (j-1))][(v * 10 + a[j])%k] += f[i][v];
		}
	}
	ll ans = f[(1 << len) - 1][0];
	for (int i = 0;i <= 9; i++) ans /= jie[cnt[i]];
	printf("%lld\n", ans);
	return 0;
}
/*
1
123434 2
*/