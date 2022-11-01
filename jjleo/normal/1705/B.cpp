#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		long long ans = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), ans += i == n ? 0 : a[i];
		long long sum = 0;
		for(int i = 1;i < n;i++){
			if(a[i] == 0){
				if(sum) ans++;
			}
			sum += a[i];
		}
		printf("%lld\n", ans);
	}
}