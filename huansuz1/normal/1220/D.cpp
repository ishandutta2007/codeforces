#include <bits/stdc++.h>
 
#define ll long long
using namespace std;
 
const int N = int(2e5) + 228;

int ok[N], n;
long long a[N];
ll cnt[100];
 
int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
		ll x = a[i];
		int res =0;
		while(x % 2 == 0){
			x /= 2;
			res++;
		}
		cnt[res]++;
	}
	int ans = 0;
	for(int i = 0; i < 70; i++){
		if(cnt[i] > cnt[ans]) ans = i;
	}
	printf("%d\n", n - cnt[ans]);
	for(int i = 1; i <= n; i++){
		ll x = a[i];
		int res =0;
		while(x % 2 == 0){
			x /= 2;
			res++;
		}
		if(res != ans){
			printf("%lld ", a[i]);
		}
	}

 
 
	return 0;
}