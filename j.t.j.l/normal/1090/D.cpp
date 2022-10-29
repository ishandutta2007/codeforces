#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> PII;

const int MAXN = 1e6 + 10;
const int MM = 1e9 + 7;

int n, m;
vector<int> E[MAXN];
int vis[MAXN];

void pts(int u, int v) {
	//cerr << u << ' ' << v << endl;
	puts("YES");
	vector<int> f;
	for (int i = 1; i <= n; i++)
		if (i != 1 && i != 2)
			f.push_back(i);
	for (int i = 1, j = 0; i <= n; i++) {
		if (i == u) printf("%d%c", 1, " \n"[i == n]);
		else if (i == v) printf("%d%c", 2, " \n"[i == n]);
		else printf("%d%c", f[j++], " \n"[i == n]);
	}
	for (int i = 1, j = 0; i <= n; i++) {
		if (i == u) printf("%d%c", 1, " \n"[i == n]);
		else if (i == v) printf("%d%c", 1, " \n"[i == n]);
		else printf("%d%c", f[j++], " \n"[i == n]);
	}
}

int main(){
	scanf("%d%d", &n, &m);
	ll nn = 1ll * n * (n - 1) / 2;
	for (int i = 1; i <= m; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (x == y) {
			;
		}
		else {
			E[x].push_back(y);
			E[y].push_back(x);
		}
	}
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		if (E[i].size() < n - 1) {
			flag = 1;
			for (int j = 1; j <= n; j++)
				vis[j] = 0;
			vis[i] = 1;
			for (auto &x : E[i])
				vis[x] = 1;
			for (int j = 1; j <= n; j++)
				if (!vis[j]){
					pts(i, j);
					break;
				}
			break;
		}
	}
	if (flag == 0) 
		puts("NO");
	return 0;
}