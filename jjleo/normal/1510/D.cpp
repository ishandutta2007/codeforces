#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int n, d;
pair<long double, int> f[maxn][10];
int a[maxn];

int main(){
	scanf("%d%d", &n, &d);
	for(int i = 1;i <= n;i++) scanf("%d", &a[i]);
	for(int i = 0;i <= n;i++) for(int j = 0;j < 10;j++) f[i][j] = {-1e18, 0};
	f[0][1] = {0, 0};
	for(int i = 0;i < n;i++) for(int j = 0;j < 10;j++){
		f[i + 1][j] = max(f[i + 1][j], {f[i][j].first, -1});
		f[i + 1][j * a[i + 1] % 10] = max(f[i + 1][j * a[i + 1] % 10], {f[i][j].first + log(a[i + 1]), j});
	}
	vector<int> v;
	int x = d;
	//for(int i = 1;i < 10;i++) if(f[n][i] > f[n][x]) x = i;
	if(f[n][x].first <= 0) return printf("-1"), 0;
	for(int i = n;i;i--){
		if(f[i][x].second != -1) v.push_back(a[i]), x = f[i][x].second;
	}
	printf("%d\n", v.size());
	for(int i = 0;i < v.size();i++) printf("%d ", v[i]);
}