#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n;
int a[maxn], x;
vector<pair<int, int> > v; 
int sum, cnt[maxn];

int main(){
	for(int i = 1;i <= 6;i++) scanf("%d", &a[i]);
	scanf("%d", &n);
	for(int i = 1;i <= n;i++){
		scanf("%d", &x);
		for(int j = 1;j <= 6;j++){
			v.push_back({x - a[j], i});
		} 
	}
	sort(v.begin(), v.end());
	int r = -1, ans = 2e9;
	for(int i = 0;i < v.size();i++){
		while(r + 1 < v.size() && sum < n){
			if((++cnt[v[++r].second]) == 1) sum++;
		}
		if(sum == n) ans = min(ans, v[r].first - v[i].first);
		if((--cnt[v[i].second]) == 0) sum--;
	}
	printf("%d", ans);
}