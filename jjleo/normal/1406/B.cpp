#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n, x;
vector<int> a, b, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		ll ans = -1e18;
		scanf("%d", &n), a.clear(), b.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x);
			if(x == 0) ans = 0;
			else if(x > 0) a.push_back(x);
			else b.push_back(-x);
		}
		c = a, d = b;
		sort(a.begin(), a.end(), greater<int>());
		sort(b.begin(), b.end(), greater<int>());
		sort(c.begin(), c.end());
		sort(d.begin(), d.end());
		if(a.size() >= 5) ans = max(ans, 1ll * a[0] * a[1] * a[2] * a[3] * a[4]);
		if(a.size() >= 4 && b.size() >= 1) ans = max(ans, -1ll * c[0] * c[1] * c[2] * c[3] * d[0]);
		if(a.size() >= 3 && b.size() >= 2) ans = max(ans, 1ll * a[0] * a[1] * a[2] * b[0] * b[1]);
		if(a.size() >= 2 && b.size() >= 3) ans = max(ans, -1ll * c[0] * c[1] * d[0] * d[1] * d[2]);
		if(a.size() >= 1 && b.size() >= 4) ans = max(ans, 1ll * b[0] * b[1] * b[2] * b[3] * a[0]);
		if(b.size() >= 5) ans = max(ans, -1ll * d[0] * d[1] * d[2] * d[3] * d[4]);
		printf("%lld\n", ans);
	}
}