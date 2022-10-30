#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n;
int a[maxn];
long long b[maxn], f[2], c[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = a[i] - b[i - 1], c[i] = min(c[i - 1], b[i]);
		bool tag = true;
		f[0] = f[1] = 1e18;
		for(int i = 1;i <= n;i++) if(b[i] < 0) tag = false;
		if(tag && !b[n]){
			puts("YES");
			continue;
		}
		tag = false;
		for(int i = n - 1;i;i--){
			if((a[i] - a[i + 1]) * ((n - i) & 1 ? 2 : -2) + b[n] != 0 || c[i - 1] < 0){
				f[(n - i) & 1] = min(f[(n - i) & 1], b[i]);
				continue;
			}
			if(f[0] + (a[i] - a[i + 1]) * ((n - i) & 1 ? 2 : -2) >= 0 && f[1] + (a[i] - a[i + 1]) * ((n - i) & 1 ? -2 : 2) >= 0 && b[i] + a[i + 1] - a[i] >= 0){
				tag = true;
				break;
			}
			f[(n - i) & 1] = min(f[(n - i) & 1], b[i]);
		}
		puts(tag ? "YES" : "NO");
	}
}