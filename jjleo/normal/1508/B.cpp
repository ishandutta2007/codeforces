#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t, n;
ll k;
int a[maxn];

ll cal(int x){
	if(x < 0) return 1;
	if(x >= 60) return 2e18;
	return 1ll << x; 
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &k);
		ll sum = 1;
		for(int i = 1;i < n && sum < k;i++) sum <<= 1;
		if(sum < k){
			puts("-1");
			continue; 
		} 
		for(int i = 1;i <= n;i++) a[i] = i;
		int last = 1;
		for(int i = 1;i <= n;i++){
			if(cal(n - i - 1) >= k){
				reverse(a + last, a + i + 1);
				last = i + 1;
			}else{
				k -= cal(n - i - 1);
			}
		}
		for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("");
	}
}