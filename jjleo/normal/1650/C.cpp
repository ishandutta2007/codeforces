#include <bits/stdc++.h>
#define maxn 200086

using namespace std;

int t, n, m;
pair<int, int> a[maxn];
int pos[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		for(int i = 1;i <= m;i++) scanf("%d%d", &pos[i], &a[i].first), a[i].second = i;
		sort(a + 1, a + 1 + m);
		int ans = 0;
		for(int i = 1;i <= n * 2;i++) ans += a[i].first;
		printf("%d\n", ans);
		vector<pair<int, int> > v;
		for(int i = 1;i <= n * 2;i++) v.push_back({pos[a[i].second], a[i].second});
		sort(v.begin(), v.end());
		for(int i = 1;i <= n;i++) printf("%d %d\n", v[i - 1].second, v[n * 2 - i].second);
		puts("");
	}
}