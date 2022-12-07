#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int n, m;
int a[maxn], b[maxn];
vector<int> v;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
		sort(a + 1, a + 1 + n);
		for(int i = 1;i <= m;i++) scanf("%d", &b[i]);
		long long ans = 1e18, sum = 0;
		for(int i = 1;i <= n - m;i++) sum += b[a[i]];
		int x = max(1, n - m + 1);
		for(int i = 0;x + i <= n;i++){
			sum += b[i + 1];
			v.push_back(b[i + 1]);
		}
		ans = min(ans, sum);
		for(int i = 0;x + i <= n;i++){
			sum -= v.back();
			v.pop_back();
			sum += b[a[x + i]];
			ans = min(ans, sum);
		}
		printf("%lld\n", ans);
	}
}