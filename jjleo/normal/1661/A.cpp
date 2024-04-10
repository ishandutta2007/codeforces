#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
int a[maxn], b[maxn];
ll f[maxn][2];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n;i++) scanf("%d", &b[i]);
		for(int i = 2;i <= n;i++){
			f[i][0] = min(f[i - 1][0] + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), f[i - 1][1] + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
			f[i][1] = min(f[i - 1][1] + abs(a[i] - a[i - 1]) + abs(b[i] - b[i - 1]), f[i - 1][0] + abs(a[i] - b[i - 1]) + abs(b[i] - a[i - 1]));
		}
		printf("%lld\n", min(f[n][0], f[n][1]));
	}
}