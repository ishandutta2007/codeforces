#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

typedef long long ll;

int t;
int n, p;
int a[maxn];
pair<int, int> b[maxn];
bool tag[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &p);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]), b[i] = {a[i], i}, tag[i] = false;
		sort(b + 1, b + 1 + n);
		int cnt = 0;
		ll ans = 0;
		for(int i = 1;i <= n;i++){
			if(b[i].first >= p) break;
			int x = b[i].second;
			int gcd = a[x];
			int y = x;
			while(y + 1 <= n && !tag[y + 1] && a[y + 1] >= a[x]){
				gcd = __gcd(gcd, a[y + 1]);
				if(gcd < a[x]) break;
				y++;
			}
			for(int j = x + 1;j <= y;j++) cnt++, ans += a[x], tag[j] = true;
			y = x, gcd = a[x];
			while(y - 1 >= 1 && !tag[y] && a[y - 1] >= a[x]){
				gcd = __gcd(gcd, a[y - 1]);
				if(gcd < a[x]) break;
				y--;
			}
			for(int j = x - 1;j >= y;j--) cnt++, ans += a[x], tag[j + 1] = true;
		}
		ans += 1ll * (n - 1 - cnt) * p;
		printf("%lld\n", ans);
	} 
}