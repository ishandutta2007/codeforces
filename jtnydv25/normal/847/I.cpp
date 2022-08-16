#include <bits/stdc++.h>

#define icin(x) scanf("%d",&x)
#define lcin(x) scanf("%lld",&x)
#define pb push_back
#define LL long long
#define F first
#define S second
#define VPI vector< pair<int,int> >
#define VVI vector< vector<int> > 
#define BC(x) __builtin_popcount(x)

using namespace std;

char data[300][300];

LL table[300][300];
int level[300][300];
int vis[300][300] = {0};

int n,m,q,p;

bool val(int i,int j)
{
	if (i<1 || i>n || j<1 || j>m || data[i][j] == '*')
		return false;
	return true;
}

int main()
{
	icin(n); icin(m);
	icin(q); icin(p);
	for(int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++)
			cin >> data[i][j];
	}

	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			int vis_label = (i-1)*n + j;
			if(data[i][j] == '.' || data[i][j] == '*')
				continue;
			int mul = data[i][j] - 'A' + 1;
			LL spow = mul*q;
			queue< pair<int,int> > q;
			level[i][j] = 0;
			vis[i][j] = vis_label;
			q.push({i,j});
			while (!q.empty()) {
				auto p = q.front();
				q.pop();
				int x = p.F, y = p.S;
				if (spow/(1ll<<(level[x][y])) == 0)
					break;
				// cerr << x << " " << y << " " << table[x][y] << endl;
				table[x][y] += spow/(1<<(level[x][y])); 
				if (val(x+1,y) && vis[x+1][y] != vis_label) {
					level[x+1][y] = level[x][y] + 1;
					vis[x+1][y] = vis_label;
					q.push({x+1,y});
				}
				if (val(x-1,y) && vis[x-1][y] != vis_label) {
					level[x-1][y] = level[x][y] + 1;
					vis[x-1][y] = vis_label;
					q.push({x-1,y});
				}
				if (val(x,y+1) && vis[x][y+1] != vis_label) {
					level[x][y+1] = level[x][y] + 1;
					vis[x][y+1] = vis_label;
					q.push({x,y+1});
				}
				if (val(x,y-1) && vis[x][y-1] != vis_label) {
					level[x][y-1] = level[x][y] + 1;
					vis[x][y-1] = vis_label;
					q.push({x,y-1});
				}
			}
		}
	}

	// for (int i=1; i<=n; i++) {
	// 	for (int j=1; j<=m; j++)
	// 		cout << table[i][j] << " ";
	// 	cout << endl;
	// }

	int ans = 0;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++)
			if (table[i][j] > p)
				ans++;
	}
	cout << ans;

	return 0;
}