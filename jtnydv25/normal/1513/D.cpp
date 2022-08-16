#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...)
#endif

struct sparse_table{
    vector<vector<int>> arr; 
    vector<int> floorlog;
    function<int(int, int)> func;
    int n;
    sparse_table(){}
    sparse_table(vector<int> & vec, function<int(int, int)> f) : n(sz(vec)), floorlog(sz(vec) + 1), func(f){
        for(int i = 0; (1 << i) <= n; i++){
			for(int j = (1 << i); j < (1 << (i + 1)) && j <= n; j++)
				floorlog[j] = i;
		}
        arr.assign(floorlog[n] + 1, vector<int>(n));

        for(int i = n - 1; i >= 0; i--){
			arr[0][i] = vec[i];
			for(int j = 1; i + (1 << j) <= n; j++){
				arr[j][i] = func(arr[j - 1][i], arr[j - 1][i + (1 << (j - 1))]);
			}
		}
    }

	int get(int i, int j){
		int k = floorlog[j - i + 1];
		return func(arr[k][i], arr[k][j - (1 << k) + 1]);
	}

	int get1(int i, int v){
		// largest position j >= i with get(i, j) >= v
		int lo = i, hi = n - 1;
		while(lo < hi){
			int mid = (lo + hi + 1) >> 1;
			if(get(i, mid) >= v) lo = mid;
			else hi = mid - 1;
		}
		return lo;
	}

	int get2(int i, int v){
		//  smallest position j <= i with get(j, i) >= v
		int lo = 0, hi = i;
		while(lo < hi){
			int mid = (lo + hi) >> 1;
			if(get(mid, i) >= v) hi = mid;
			else lo = mid + 1;
		}
		return lo;
	}
};

struct dsu{
    int n;
    vector<int> par;
    dsu(int n) : n(n), par(n){
        iota(par.begin(), par.end(), 0);
    }
    int root(int x){
        return x == par[x] ? x : (par[x] = root(par[x]));
    }
    bool merge(int x, int y){
        x = root(x); y = root(y);
        if(x == y) return 0;
		if(x > y) swap(x, y);
        par[x] = y;
        return 1;
    }
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, p; cin >> n >> p;
		vector<int> a(n), perm(n);
		for(int & x : a) cin >> x;
		iota(all(perm), 0);
		sort(all(perm), [&](int i, int j){return a[i] < a[j];});
		sparse_table st_min(a, [](int i, int j){return min(i, j);});
		sparse_table st_gcd(a, [](int i, int j){return __gcd(i, j);});
		dsu D(n);
		ll ans = 0;
		for(int ind : perm){
			int x = a[ind];
			int L = max(st_min.get2(ind, x), st_gcd.get2(ind, x));
			int R = min(st_min.get1(ind, x), st_gcd.get1(ind, x));

			x = min(x, p);
			// merge [L, R] with x
			int u = D.root(L);
			while(u < R){
				D.merge(u, u + 1);
				ans += x;
				u = D.root(u);
			}
		}
		int L = 0, R = n - 1, x = p;
		int u = D.root(L);
		while(u < R){
			D.merge(u, u + 1);
			ans += x;
			u = D.root(u);
		}
		cout << ans << "\n";
	}
}