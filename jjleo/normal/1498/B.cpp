#include <bits/stdc++.h>
#define maxn 1000086

using namespace std;

typedef long long ll;

int t;
int n;
ll w, a[maxn];
int cnt[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%lld", &n, &w);
		for(int i = 1;i <= n;i++) scanf("%lld", &a[i]), cnt[a[i]]++;
		int ans = 0;
		while(n){
			ll x = w;
			for(int i = 1 << 19;i;i >>= 1){
				while(x >= i && cnt[i]) cnt[i]--, x -= i, n--;
			}
			ans++;
		}
		printf("%d\n", ans);
	}
}