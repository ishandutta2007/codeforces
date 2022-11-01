#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#define f first
#define s second
#define pb push_back
#define mp make_pair

const int maxn = 100500;
const int inf = 2e9;
const double eps = 1e-8;
const int base = 1073676287;

vector <int> edge[maxn];
int used[maxn];
int ans[maxn];

int n, k;

void dfs(int v, int l, int r) {
	used[v] = true;
	for (auto to : edge[v]) {
		ans[to] += ans[v];
		int new_l = max(1, to - k);
		int new_r = min(n, to + k);
		int intersection_len = max(0, r - new_l + 1);
		ans[to] += (new_r - new_l + 1) - intersection_len;
		dfs(to, new_l, new_r);
	}
}

int main()
{
    srand(time(0));
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    // ios_base::sync_with_stdio(false);
    scanf ("%d%d", &n, &k);
    for (int i = 1; i <= n; ++i) {
    	int x;
    	scanf ("%d", &x);
    	if (x)
    		edge[x].pb(i);
    }
    for (int i = 1; i <= n; ++i)
    	if (!used[i]) {
    		int l = max(1, i - k);
    		int r = min(n, i + k);
    		ans[i] = r - l + 1;
    		dfs(i, l, r);
    	}
    for (int i = 1; i <= n; ++i)
    	printf ("%d ", ans[i]);
    return 0;
}