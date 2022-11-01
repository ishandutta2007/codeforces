#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int n, q;
int a[maxn];
int opt, x, y;
bool tag[maxn];
ll tot = 0;

int main(){
	scanf("%d%d", &n, &q);
	for(int i = 1;i <= n;i++) a[i] = i;
	int l = max(1, n - 19);
	while(q--){
		scanf("%d", &opt);
		if(opt == 1){
			scanf("%d%d", &x, &y);
			ll ans = 0;
			if(x < l) ans += 1ll * (x + min(l - 1, y)) * (min(l - 1, y) - x + 1) / 2;
			for(int i = max(x, l);i <= y;i++) ans += a[i];
			printf("%lld\n", ans);
		}else{
			scanf("%d", &x), tot += x;
			for(int i = l;i <= n;i++) tag[i] = false;
			ll sum = 1, rk = tot;
			for(int i = 1;i < n - l + 1;i++) sum *= i;
			for(int i = l;i < n;i++){
				int k = rk / sum + 1;
				rk -= (k - 1) * sum;
				for(int j = l;j <= n;j++){
					if(tag[j]) continue;
					if(!(--k)){
						tag[j] = true;
						a[i] = j;
						break;
					}
				}
				sum /= (n - i);
			}
			for(int i = l;i <= n;i++) if(!tag[i]) a[n] = i;
			//for(int i = 1;i <= n;i++) printf("%d ", a[i]);puts("---");
		}
	}
}