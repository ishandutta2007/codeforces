#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> pii;

const int N = 300005, inf = 1e9;

int n, ans[N];
vector<int> a[N];

void solve () {
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		ans[i] = inf;
		a[i].clear();
		a[i].push_back(0);
	}
	for(int i=1;i<=n;i++) {
		int T;
		scanf("%d",&T);
		a[T].push_back(i);
	}
	for(int i=1;i<=n;i++) {
		a[i].push_back(n+1);
		int mx = 1;
		for(int j=1;j<(int)a[i].size();j++) {
			mx = max(mx, a[i][j] - a[i][j-1]);
		}
		ans[mx] = min(ans[mx], i);
	}
	for(int i=1;i<=n;i++) {
		printf("%d ", ans[i] == inf ? -1 : ans[i]);
		ans[i+1] = min(ans[i+1], ans[i]);
	}
	puts("");
}

int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--) solve();
}