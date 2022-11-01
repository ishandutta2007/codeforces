#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, n0;
int ans;

ll a[maxn], b[maxn];
map<ll, bool> mp;

inline void check(ll x){
	if(x <= 1) return;
	int sup = (int)sqrt(x) + 3;
	ll j = x;
	for(int i = 2;i <= sup && j != 1;i++){
		if(j % i == 0){
			while(j % i == 0) j /= i;
			if(mp[i]) continue;
			mp[i] = true;
			int sum = 0;
			for(int k = 1;k <= n;k++){
				sum += a[k] > i ? min(a[k] % i, i - a[k] % i) : i - a[k];
				if(sum >= n) break;
			}
			if(sum < ans) ans = sum;
			//printf("%d %d--\n", ans, i);
		}
	}
	if(j ^ 1){
		if(mp[j]) return;
		mp[j] = true;
		ll sum = 0;//debug: ll 
		for(int k = 1;k <= n;k++){
			sum += a[k] > j ? min(a[k] % j, j - a[k] % j) : j - a[k];
			if(sum >= n) break;
		}
		if(sum < ans) ans = sum;
	}
}

int main(){
	scanf("%d", &n), ans = n;
	for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), b[i] = a[i];
	sort(b + 1, b + 1 + n);
	//n0 = unique(b + 1, b + 1 + n) - (b + 1);
	random_shuffle(b + 1, b + 1 + n);
    //reverse(b + 1, b + 1 + n0);
	for(int i = 1;i <= n && clock() / (double)CLOCKS_PER_SEC < 2.0;i++) check(b[i] - 1), check(b[i]), check(b[i] + 1);
	printf("%d", ans);
}