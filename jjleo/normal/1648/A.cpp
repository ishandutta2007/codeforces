#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

typedef long long ll;

int n, m; 
int a[maxn]; 
vector<int> v[maxn];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) scanf("%d", &a[(i - 1) * m + j]), v[a[(i - 1) * m + j]].push_back(i);
	ll ans = 0;
	for(int i = 1;i < maxn;i++){
		ll sum = 0;
		sort(v[i].begin(), v[i].end());
		for(int j = 0;j < v[i].size();j++){
			ans += 1ll * j * v[i][j] - sum;
			sum += v[i][j];
		}
		v[i].clear();
	}
	for(int i = 1;i <= n;i++) for(int j = 1;j <= m;j++) v[a[(i - 1) * m + j]].push_back(j);
	for(int i = 1;i < maxn;i++){
		ll sum = 0;
		sort(v[i].begin(), v[i].end());
		for(int j = 0;j < v[i].size();j++){
			ans += 1ll * j * v[i][j] - sum;
			sum += v[i][j];
		}
	}
	printf("%lld", ans);
}