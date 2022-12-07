#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
long long a[maxn];
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		ans = 0;
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
		for(int i = 1;i <= n;i++){
			a[i] += a[i - 1];
			if(a[i] < 0) ans -= a[i], a[i] = 0;
		}
		printf("%lld\n", ans);
	}
		
}