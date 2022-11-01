#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

typedef long long ll;

int a[maxn];

int n;
ll sum[maxn], p[maxn], m[maxn];
int x;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= (n + 1) / 2;i++) scanf("%d", &a[i]), sum[i] = sum[i - 1] + a[i];
	scanf("%d", &x);
	for(int i = (n + 1) / 2 + 1;i <= n;i++) sum[i] = sum[i - 1] + x;
	for(int i = 2;i <= n;i++) p[i] = p[i - 1] + x - a[i - 1], m[i] = min(m[i - 1], p[i]);
	for(int i = n / 2 + 1;i <= n;i++){
		if(sum[i] + m[n - i + 1] > 0) return printf("%d", i), 0;
	}
	printf("-1");
}