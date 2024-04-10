#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n, x, y;
int c[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &x, &y);
		for(int i = 1;i <= 6;i++) scanf("%d", &c[i]);
		ll x1 = min(c[6], c[1] + c[5]), x2 = min(c[3], c[2] + c[4]);
		ll y1 = min(c[2], c[1] + c[3]), y2 = min(c[5], c[4] + c[6]);
		ll xy1 = min(c[1], c[2] + c[6]), xy2 = min(c[4], c[3] + c[5]);
		if(1ll * x * y >= 0){
			if(x > 0 || y > 0) printf("%lld\n", min(x, y) * xy1 + (x - min(x, y)) * x1 + (y - min(x, y)) * y1);
			else x = -x, y = -y, printf("%lld\n", min(x, y) * xy2 + (x - min(x, y)) * x2 + (y - min(x, y)) * y2);
		}else{
			ll ans = 0;
			if(x > 0) ans += x * x1;
			else ans += -x * x2;
			if(y > 0) ans += y * y1;
			else ans += -y * y2;
			printf("%lld\n", ans);
		}
	}
}