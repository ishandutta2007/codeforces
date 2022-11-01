#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, k;
vector<int> v[3];
int t, a, b;
int ans = 2e9;

int main(){
	scanf("%d%d", &n, &k);
	while(n--){
		scanf("%d%d%d", &t, &a, &b);
		if(!a && !b) continue;
		if(a && b) v[0].push_back(t);
		else if(a) v[1].push_back(t);
		else v[2].push_back(t);
	}
	if(v[0].size() + v[1].size() < k || v[0].size() + v[2].size() < k) return printf("-1"), 0;
	for(int i = 0;i < 3;i++) sort(v[i].begin(), v[i].end());
	for(int i = 0;i < 3;i++){
		for(int j = 1;j < v[i].size();j++) v[i][j] += v[i][j - 1];
	}
	for(int i = 0;i < k && i < v[0].size();i++){
		if(k - 2 - i < v[1].size() && k - 2 - i < v[2].size()) ans = min(ans, v[0][i] + v[1][k - 2 - i] + v[2][k - 2 - i]);
	}
	if(v[0].size() >= k) ans = min(ans, v[0][k - 1]);
	if(v[1].size() >= k && v[2].size() >= k) ans = min(ans, v[1][k - 1] + v[2][k - 1]);
	printf("%d", ans);
}