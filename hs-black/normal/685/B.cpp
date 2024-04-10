#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 305000;
int f[N], siz[N], son[N], n;
vector<int> v[N];

int read(void) {
	int x = 0;
	char c = getchar();
	while (!isdigit(c)) c = getchar();
	while (isdigit(c)) {
		x = (x << 3) + (x << 1) + c - '0';
		c = getchar();
	}
	return x;
}

int mx[N];
void dfs(int x) {
	siz[x] = 1; son[x] = x; 
	for (int i = 0;i < v[x].size(); i++) {
		int y = v[x][i]; dfs(y);
		siz[x] += siz[y];
		if (siz[y] > siz[mx[x]]) mx[x] = y;
	}
	int z = son[mx[x]];
	if (z) while (z != x) {
		if (siz[mx[z]] * 2 <= siz[x] && siz[x] <= siz[z] * 2) {
			son[x] = z;
			return;
		}
		z = f[z];
	}
}
		
int q;
int main() {
	n = read(), q = read();
	for (int i = 2;i <= n; i++) {
		f[i] = read(); 
		v[f[i]].push_back(i);
	}
	dfs(1);
	while (q--) printf ("%d\n", son[read()]);
	return 0;
}