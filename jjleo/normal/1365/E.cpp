#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n;
ll a[maxn];
ll ans;

int main(){
	scanf("%d", &n);
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]);
	ans = a[1] | a[2] | a[3];
	for(int i = 1;i <= n;i++){
		for(int j = 1;j < i;j++){
			for(int k = 1;k < j;k++){
				ans = max(ans, a[i] | a[j] | a[k]);
			}
		}
	}
	printf("%lld", ans);
}