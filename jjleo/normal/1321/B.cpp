#include <bits/stdc++.h>
#define maxn 800086

using namespace std;

int n;
int b[maxn], a[maxn];
long long f[maxn], ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &b[i]), a[i] = i - b[i] + 4e5;
	}
	for(int i = 1;i <= n;i++){
		ans = max(ans, f[a[i]] += b[i]);
	}
	printf("%lld", ans);
}