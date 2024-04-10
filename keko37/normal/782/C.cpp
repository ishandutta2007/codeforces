#include<iostream>
#include<vector>

using namespace std;

const int MAXN = 200005;

int n, a, b, k;
vector <int> v[MAXN];
int sol[MAXN];

void dfs (int cvor, int par) {
	int col=1;
	for (int i=0; i<v[cvor].size(); i++) {
		int sus=v[cvor] [i];
		if (sus==par) continue;
		while (col==sol[cvor] || col==sol[par]) col++;
		sol[sus]=col;
		dfs(sus, cvor);
		col++;
	}
}

int main () {
	cin >> n;
	for (int i=0; i<n-1; i++) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	sol[1]=1;
	dfs(1, 0);
	for (int i=1; i<=n; i++) {
		k=max(k, sol[i]);
	}
	cout << k << endl;
	for (int i=1; i<=n; i++) {
		cout << sol[i] << " ";
	}
	return 0;
}