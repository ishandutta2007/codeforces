#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t;
int n, k;
map<int, int> mp;
int x;
long long ans;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		mp.clear();
		ans = 0;
		while(n--){
			scanf("%d", &x);
			if(x % k){
				mp[x % k]++;
				ans = max(ans, (k - x % k) % k + 1ll * k * (mp[x % k] - 1));
			}
		}
		if(!ans) puts("0");
		else printf("%lld\n", ans + 1);
	}
}