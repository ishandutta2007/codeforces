#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, m;
int a[maxn], b[maxn], c[maxn], d[maxn];
vector<pair<int, int> > v;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) scanf("%d%d", &a[i], &b[i]);
	for(int i = 1;i <= m;i++) scanf("%d%d", &c[i], &d[i]);
	for(int i = 1;i <= n;i++){
		for(int j = 1;j <= m;j++){
			if(a[i] <= c[j] && b[i] <= d[j]){
				v.push_back({c[j] - a[i] + 1, d[j] - b[i] + 1});
			}
		}
	}
	if(v.empty()) return printf("0"), 0;
	sort(v.begin(), v.end());
	int ans = 1e9;
	for(int i = (int)v.size() - 1;~i;i--){
		ans = min(ans, v[i].first + (i + 1 < v.size() ? v[i + 1].second : 0));
		if(i + 1 < v.size()) v[i].second = max(v[i].second, v[i + 1].second);
	}
	ans = min(ans, v[0].second);
	printf("%d", ans);
}