#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int T;
int n, t, a, b;
int c[2];

pair<int, int> p[maxn];

int main(){
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d%d", &n, &t, &a, &b);
		c[0] = c[1] = 0;
		for(int i = 1;i <= n;i++) scanf("%d", &p[i].second), c[p[i].second]++;
		for(int i = 1;i <= n;i++) scanf("%d", &p[i].first);
		sort(p + 1, p + 1 + n);
		p[n + 1].first = t + 1;
		int cnt = 0, ans = 0;
		long long sum = 0;
		if(true){
			int x = p[1].first - 1;
			int y = min(c[0], x / a);
			ans = max(ans, y + min(c[1], (x - y * a) / b));
		}
		for(int i = 1;i <= n;i++){
			cnt++, sum += p[i].second ? b : a;
			c[p[i].second]--;
			if(i != n && p[i + 1].first == p[i].first) continue;
			if(sum > p[i + 1].first - 1) continue;
			//printf("%d %d--\n", i, sum);
			int x = p[i + 1].first - 1 - sum;
			int y = min(c[0], x / a);
			ans = max(ans, cnt + y + min(c[1], (x - y * a) / b));
		}
		if(sum <= t){
			int x = t - sum;
			int y = min(c[0], x / a);
			ans = max(ans, cnt + y + min(c[1], (x - y * a) / b));
		}
		
		printf("%d\n", ans);
	}
}