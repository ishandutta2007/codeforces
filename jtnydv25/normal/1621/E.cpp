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

// 0-indexed
template<class T>
struct sparse_table{
    vector<vector<T>> arr; 
    vector<int> floorlog;
    function<T(T, T)> func;
    int n;
    sparse_table(){}
    sparse_table(vector<T> & vec, function<T(T, T)> f) : n(sz(vec)), floorlog(sz(vec) + 1), func(f){
        for(int i = 0; (1 << i) <= n; i++){
			for(int j = (1 << i); j < (1 << (i + 1)) && j <= n; j++)
				floorlog[j] = i;
		}
        arr.assign(floorlog[n] + 1, vector<T>(n));

        for(int i = n - 1; i >= 0; i--){
			arr[0][i] = vec[i];
			for(int j = 1; i + (1 << j) <= n; j++){
				arr[j][i] = func(arr[j - 1][i], arr[j - 1][i + (1 << (j - 1))]);
			}
		}
    }

	T get(int i, int j){
		if(i > j) return T(1);
		int k = floorlog[j - i + 1];
		return func(arr[k][i], arr[k][j - (1 << k) + 1]);
	}
};

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, m; cin >> n >> m;
		vector<vector<int>> ages(m);
		vector<ll> sums(m), num(m);
		vector<int> a(n);
		for(int& x: a) cin >> x;
		sort(all(a)); reverse(all(a)); a.resize(m); reverse(all(a));
		for(int i = 0; i < m; i++){
			cin >> num[i];
			ages[i].resize(num[i]);
			for(int & u: ages[i]){
				cin >> u;
				sums[i] += u;
			}
		}
		vector<int> perm(m), position(m);
		iota(all(perm), 0);
		sort(all(perm), [&](int i, int j){return sums[i] * num[j] < sums[j] * num[i];});
		vector<int> good1(m), good2(m), good3(m);
		for(int i = 0; i < m; i++){
			int ind = perm[i];
			position[ind] = i;
			good1[i] = sums[ind] <= a[i] * 1LL * num[ind];
			if(i) good2[i] = sums[ind] <= a[i - 1] * 1LL * num[ind];
			if(i + 1 < m) good3[i] = sums[ind] <= a[i + 1] * 1LL * num[ind];
		}

		sparse_table<int> st1(good1, [](int i, int j){return min(i, j);});
		sparse_table<int> st2(good2, [](int i, int j){return min(i, j);});
		sparse_table<int> st3(good3, [](int i, int j){return min(i, j);});

		for(int i = 0; i < m; i++){
			int ind = position[i];
			for(int j : ages[i]){
				// new position
				ll S = sums[i] - j, cnt = num[i] - 1;
				int lo = 0, hi = m;
				while(lo < hi){
					int mid = (lo + hi) / 2;
					int id = perm[mid];
					if(S * 1LL * num[id] <= sums[id] * 1LL * cnt) hi = mid;
					else lo = mid + 1;
				}

				int pos = lo;
				if(ind < pos) pos--;
				if(S > cnt * 1LL * a[pos]){
					cout << 0;
					continue;
				}
				pos = lo;
				if(ind < pos){
					int ok = 1;
					if(!st1.get(0, ind - 1)) ok = 0;
					if(!st1.get(pos, m - 1)) ok = 0;
					if(!st2.get(ind + 1, pos - 1)) ok = 0;
					cout << ok;
				} else{
					int ok = 1;
					if(!st1.get(0, pos - 1)) ok = 0;
					if(!st1.get(ind + 1, m - 1)) ok = 0;
					if(!st3.get(pos, ind - 1)) ok = 0;
					cout << ok;
				}
			}
		}
		cout << endl;
	}
}