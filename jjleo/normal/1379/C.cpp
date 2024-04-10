#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n, m;
long long ans;
pair<int, int> a[maxn];
int b[maxn];
long long c[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		ans = 0;
		for(int i = 1;i <= m;i++) scanf("%d%d", &a[i].second, &a[i].first), b[i] = a[i].second;
		sort(a + 1, a + 1 + m), sort(b + 1, b + 1 + m);
		c[m + 1] = 0;
		for(int i = m;i;i--) c[i] = b[i] + c[i + 1];
		if(n <= m) ans = c[m + 1 - n];
		for(int i = 1;i <= m;i++){
			
			int j = lower_bound(b + 1, b + 1 + m, a[i].first) - b;
			int x = m + 1 - j;
			int y = n - x - 1;
			//printf("%d %d %d--\n", a[i].first, j, c[j]);
			long long sum = 0;
			if(a[i].second >= a[i].first) y++;
			else sum += a[i].second;
			if(y < 0) continue;
		    sum += c[j] + 1ll * a[i].first * y;
		    ans = max(ans, sum);
		}
		printf("%lld\n", ans);
	}
}