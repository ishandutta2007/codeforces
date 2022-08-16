#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

struct dsu{
    int n;
    vector<int> par, sizes;
	int mx;

	int sum;
    dsu(int n) : n(n), par(n), sizes(n), mx(0), sum(0){
        iota(par.begin(), par.end(), 0);
		fill(all(sizes), 1);
    }
    int root(int x){
        return x == par[x] ? x : (par[x] = root(par[x]));
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return 0;
        par[x] = y;
		sum++;
		sizes[y] += sizes[x];
		mx = max(mx, sizes[y] - 1);
        return 1;
    }
};

const int INF = 1e9;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, d;
	cin >> n >> d;
	dsu D(n);
	vector<int> perm(n);
	iota(all(perm), 0);

	vector<int> dp(n + 1);
	for(int i = 1; i <= d; i++){
		int x, y; cin >> x >> y;
		x--; y--;
		D.merge(x, y);
		int comps = n - D.sum;
		random_shuffle(all(perm));
		int sum = 0;
		fill(all(dp), INF);
		dp[0] = 0;
		for(int j : perm) if(D.root(j) == j){
			int s = D.sizes[j];
			for(int r = sum; r >= 0; r--) if(dp[r] != INF){
				dp[r + s] = min(dp[r + s], dp[r] + 1);
			}
			sum += s;
		}
		for(int it = n; it >= 1; it--) if(dp[it] != INF){
			int rem = n - it;
			int h = comps - dp[it];
			int e = rem - h;
			if(i - e >= it - 1){
				cout << it - 1 << endl;
				break;
			}
		}
	}
}