#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 100500;
long double f[N];
int n;
vector<int> v[N];
void dfs(int x,int fa) {
	int siz = 0;
	for (int i = 0;i < v[x].size(); i++) {
		int y = v[x][i];
		if (y == fa) continue;
		dfs(y, x);
		siz++;
		f[x] += f[y];
	}
	if (siz) f[x] = f[x] / (double)siz + 1;
}
int main() {
	cin >> n;
	for (int i = 1;i < n; i++) {
		int x, y;
		scanf ("%d%d", &x, &y);
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1, 0);
	printf ("%.8lf\n", (double)f[1]);
	return 0;
}