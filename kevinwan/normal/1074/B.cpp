#include <bits/stdc++.h>
#define m(x,y) (a[x]>a[y]?x:y)
using namespace std;
typedef long long ll;
typedef pair<int, int> pii; 
typedef pair<ll, ll> pll;
#define mn (1<<17)
vector<int> g[1001];
bool me[1001],you[1001];
int m[1001],cur;
void dfs(int x, int p) {
	if (me[x])cur = x;
	m[x] = cur;
	for (int y : g[x]) {
		if (y == p)continue;
		if (me[x])cur = x;
		dfs(y,x);
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b, i, q, w,s,k;
		for (i = 1; i <= 1000; i++)g[i].clear();
		memset(me, 0, sizeof(me));
		memset(you, 0, sizeof(you));
		memset(m, 0, sizeof(m));
		scanf("%d", &n);
		for (i = 0; i < n - 1; i++)cin >> a >> b , g[a].push_back(b), g[b].push_back(a);
		cin >> q;
		for (i = 0; i < q; i++)cin >> a, me[a] = 1,s=a;
		dfs(s, 0);
		cin >> w;
		for (i = 0; i < w; i++)cin >> a,you[a]=1,k=a;
		cout << "B "<<k<<endl;
		cin >> a;
		if (me[a]) {
			cout << "C " << a<<endl;
			continue;
		}
		cout << "A " << m[a] << endl;
		cin >> b;
		if (you[b])cout << "C " << m[a] << endl;
		else cout << "C -1" << endl;
	}
	getchar(); getchar();
}