#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn];
int f[maxn];

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	int m = 0;
	for(int i = 1;i <= n;i++) if(a[i] ^ a[i - 1]) a[++m] = a[i];
	if(m == 1) return printf("1"), 0;
	memset(f, -1, sizeof(f));
	int mx = -1;
	for(int i = 2;i <= m;i++){
		f[a[i - 1]] = max(f[a[i - 1]], max(mx, f[a[i]] + 1));
		mx = max(mx, f[a[i - 1]]);
	}
	printf("%d", m - mx);
}