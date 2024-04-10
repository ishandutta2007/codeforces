#include <bits/stdc++.h>
#define maxn 200086

using namespace std;
int t;
int n;
int a[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n, greater<int>());
		int l = 1;
		long long ans = 0;
		for(int i = 1;i <= n;i++){
			while(a[l] - a[i] > 2) l++;
			if(i ^ l) ans += 1ll * (i - l - 1) * (i - l - 1 + 1) / 2;
		}
		printf("%lld\n", ans);
	}
}