#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		long long sum = 0;
		for(int i = 1;i < n;i++) sum += a[i];
		printf("%.10f\n", 1.0 * sum / (n - 1) + a[n]);
	}
}