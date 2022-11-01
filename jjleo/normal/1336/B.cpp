#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int t;
int n1, n2, n3;
int a[maxn], b[maxn], c[maxn];
int x, y, d ,e;

ll ans;

inline ll sq(ll x){
	return x * x;
}

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &n1, &n2, &n3);
		ans = 9223372036854775807;
		for(int i = 1;i <= n1;i++) scanf("%d", &a[i]);
		for(int i = 1;i <= n2;i++) scanf("%d", &b[i]);
		for(int i = 1;i <= n3;i++) scanf("%d", &c[i]);
		sort(a + 1, a + 1 + n1), sort(b + 1, b + 1 + n2), sort(c + 1, c + 1 + n3);
		n1 = unique(a + 1, a + 1 + n1) - (a + 1), n2 = unique(b + 1, b + 1 + n2) - (b + 1), n3 = unique(c + 1, c + 1 + n3) - (c + 1);
		for(int i = 1;i <= n1;i++){
			x = min((int)(lower_bound(b + 1, b + 1 + n2, a[i]) - b), n2);
			y = min((int)(lower_bound(c + 1, c + 1 + n3, a[i]) - c), n3);
			d = max(1, x - 1);
			e = max(1, y - 1);
			ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[y]) + sq(b[x] - c[y]));
			ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[e]) + sq(b[x] - c[e]));
			ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[y]) + sq(b[d] - c[y]));
			ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[e]) + sq(b[d] - c[e]));
		}
		for(int i = 1;i <= n2;i++){
			x = min((int)(lower_bound(a + 1, a + 1 + n1, b[i]) - a), n1);
			y = min((int)(lower_bound(c + 1, c + 1 + n3, b[i]) - c), n3);
			d = max(1, x - 1);
			e = max(1, y - 1);
			ans = min(ans, sq(b[i] - a[x]) + sq(b[i] - c[y]) + sq(a[x] - c[y]));
			ans = min(ans, sq(b[i] - a[x]) + sq(b[i] - c[e]) + sq(a[x] - c[e]));
			ans = min(ans, sq(b[i] - a[d]) + sq(b[i] - c[y]) + sq(a[d] - c[y]));
			ans = min(ans, sq(b[i] - a[d]) + sq(b[i] - c[e]) + sq(a[d] - c[e]));
		}
		for(int i = 1;i <= n3;i++){
			x = min((int)(lower_bound(a + 1, a + 1 + n1, c[i]) - a), n1);
			y = min((int)(lower_bound(b + 1, b + 1 + n2, c[i]) - b), n2);
			d = max(1, x - 1);
			e = max(1, y - 1);
			ans = min(ans, sq(c[i] - a[x]) + sq(c[i] - b[y]) + sq(a[x] - b[y]));
			ans = min(ans, sq(c[i] - a[x]) + sq(c[i] - b[e]) + sq(a[x] - b[e]));
			ans = min(ans, sq(c[i] - a[d]) + sq(c[i] - b[y]) + sq(a[d] - b[y]));
			ans = min(ans, sq(c[i] - a[d]) + sq(c[i] - b[e]) + sq(a[d] - b[e]));
		}
		/*for(int i = 1;i <= n1;i++){
			x = min((int)(lower_bound(b + 1, b + 1 + n2, a[i]) - b), n2);
			y = min((int)(lower_bound(c + 1, c + 1 + n3, a[i]) - c), n3);
			d = max(1, x - 1);
			e = max(1, y - 1);
			ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[y]) + sq(b[x] - c[y]));
			ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[e]) + sq(b[x] - c[e]));
			ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[y]) + sq(b[d] - c[y]));
			ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[e]) + sq(b[d] - c[e]));
			if(x + 1 && x + 1 <= n2 && y && y <= n3) ans = min(ans, sq(a[i] - b[x + 1]) + sq(a[i] - c[y]) + sq(b[x + 1] - c[y]));
			if(x && x <= n2 && y + 1 && y + 1 <= n3) ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[y + 1]) + sq(b[x] - c[y + 1]));
			if(d - 1 && d - 1 <= n2 && e && e <= n3) ans = min(ans, sq(a[i] - b[d - 1]) + sq(a[i] - c[e]) + sq(b[d - 1] - c[e]));
			if(d && d <= n2 && e - 1 && e - 1 <= n3) ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[e - 1]) + sq(b[d] - c[e - 1]));
		*/	
			
			
			
			
			/*if(x && x <= n2 && y && y <= n3) ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[y]) + sq(b[x] - c[y]));
			if(x && x <= n2 && e && e <= n3) ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[e]) + sq(b[x] - c[e]));
			if(d && d <= n2 && y && y <= n3) ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[y]) + sq(b[d] - c[y]));
			if(d && d <= n2 && e && e <= n3) ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[e]) + sq(b[d] - c[e]));
			if(x + 1 && x + 1 <= n2 && y && y <= n3) ans = min(ans, sq(a[i] - b[x + 1]) + sq(a[i] - c[y]) + sq(b[x + 1] - c[y]));
			if(x && x <= n2 && y + 1 && y + 1 <= n3) ans = min(ans, sq(a[i] - b[x]) + sq(a[i] - c[y + 1]) + sq(b[x] - c[y + 1]));
			if(d - 1 && d - 1 <= n2 && e && e <= n3) ans = min(ans, sq(a[i] - b[d - 1]) + sq(a[i] - c[e]) + sq(b[d - 1] - c[e]));
			if(d && d <= n2 && e - 1 && e - 1 <= n3) ans = min(ans, sq(a[i] - b[d]) + sq(a[i] - c[e - 1]) + sq(b[d] - c[e - 1]));*/
		printf("%lld\n", ans);
	}
}