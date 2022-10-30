#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, k;
int a[maxn];
ll f[maxn], F[maxn];
ll val;
int l = 1, r, cnt[maxn];

inline void cal(int L, int R){
	while(l > L) val += cnt[a[--l]], cnt[a[l]]++;
	while(r < R) val += cnt[a[++r]], cnt[a[r]]++;
	while(l < L) cnt[a[l]]--, val -= cnt[a[l++]];
	while(r > R) cnt[a[r]]--, val -= cnt[a[r--]]; 
}

void solve(int l, int r, int L, int R){
	if(l > r) return;
	int mid = l + r >> 1, x = 0;
	f[mid] = 1e18;
	for(int i = L;i <= R && i < mid;i++){
		cal(i + 1, mid);
		if(F[i] + val < f[mid]) f[mid] = F[i] + val, x = i;
	}
	solve(l, mid - 1, L, x), solve(mid + 1, r, x, R);
}

int main(){
	scanf("%d%d", &n, &k);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	memset(F, 0x3f, sizeof(F)), F[0] = 0;
	while(k--){
		solve(1, n, 0, n - 1);
		memcpy(F, f, sizeof(f));
	}
	printf("%lld", f[n]);
}