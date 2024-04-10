#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int n;
int x;
int cnt[30];
int sum;
long long ans;

int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &x);
		for(int i = 1 << 19, j = 19;i;i >>= 1, j--){
			if(x & i) cnt[j]++, sum++;
		}
	}
	while(sum){
		x = 0;
		for(int i = 1 << 19, j = 19;i;i >>= 1, j--){
			if(cnt[j]){
				cnt[j]--, sum--, x += i;
			}
		}
		ans += 1ll * x * x;
	}
	printf("%lld", ans);
	
}