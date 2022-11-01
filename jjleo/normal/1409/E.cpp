#include <bits/stdc++.h>
#define maxn 600086

using namespace std;

int t;
int n, k;
vector<int> v;
int x[maxn], y;
int a[maxn];
int pre[maxn], suf[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &k);
		v.clear();
		for(int i = 1;i <= n;i++){
			scanf("%d", &x[i]);
			v.push_back(x[i]);
			v.push_back(x[i] - k);
			v.push_back(x[i] + k);
		}
		for(int i = 1;i <= n;i++) scanf("%d", &y);
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		int m = v.size();	
		for(int i = 1;i <= m;i++) a[i] = 0;
		for(int i = 1;i <= n;i++) a[lower_bound(v.begin(), v.end(), x[i]) - v.begin() + 1]++;
		for(int i = 1;i <= m;i++) a[i] += a[i - 1];
		//for(int i = 1;i <= m;i++) printf("%d ", a[i]);
		//puts("---");
		for(int i = 1;i <= m;i++){
			pre[i] = pre[i - 1];
			if(a[i] ^ a[i - 1]) pre[i] = max(pre[i], a[i] - a[lower_bound(v.begin(), v.end(), v[i - 1] - k) - v.begin()]);
			//printf("%d--\n", pre[i]);
		}
		suf[m + 1] = 0;
		for(int i = m;i;i--){
			suf[i] = suf[i + 1];
			if(a[i] ^ a[i - 1]) suf[i] = max(suf[i], a[lower_bound(v.begin(), v.end(), v[i - 1] + k) - v.begin() + 1] - a[i - 1]);
			//printf("%d--\n", lower_bound(v.begin(), v.end(), v[i - 1] + k) - v.begin() + 1);
		}
		int ans = 0;
		for(int i = 1;i < m;i++) ans = max(ans, pre[i] + suf[i + 1]);
		printf("%d\n", ans);
	}
	
}