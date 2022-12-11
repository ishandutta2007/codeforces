#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

vector<vector<int> > g;
vector<int> sum;

int dfs(int v) {
	int cnt = 0;
	for (int to : g[v]) {
		cnt += dfs(to);
	}
	if (g[v].empty()) {
		++sum[1];
		return 1;
	}
	++sum[cnt];
	return cnt;
}

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    if (n == 1) {
    	cout << "1\n";
    	return 0;
    }

    g.resize(n);
    for (int i = 1; i < n; ++i) {
    	int p;
    	cin >> p;
    	--p;
    	g[p].pb(i);
    }

    sum.resize(n + 1);
    dfs(0);

    for (int i = 2; i <= n; ++i) {
    	sum[i] += sum[i - 1];
    }

    int put = 0;
    for (int i = 1; i <= n; ++i) {
    	while (put < sum[i]) {
    		cout << i << " ";
    		++put;
    	}
    }
    cout << "\n";

}