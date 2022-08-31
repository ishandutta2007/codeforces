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
const int B = 500;
const int INF = 1 << 30;
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
		if(i > j) return INF;
		int k = floorlog[j - i + 1];
		return func(arr[k][i], arr[k][j - (1 << k) + 1]);
	}
};
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int n, k, q; cin >> n >> q >> k;

	vector<int> a(n);

	for(int& x: a) cin >> x;

	sparse_table<int> st(a, [](int i, int j){return min(i, j);});

	vector<vector<int>> queries((n - 1) / B + 1);

	vector<int> L(q), R(q);

	vector<ll> answers(q);

	for(int  i = 0; i < q; i++){
		cin >> L[i] >> R[i];
		L[i]--; R[i]--;
		queries[L[i] / B].push_back(i);
	}

	vector<ll> arr(n);

	for(int i = 0; i <= (n - 1) / B; i++){
		if(queries[i].empty()) continue;
		int cur = INF;
		fill(all(arr), 0);
		int p = (i + 1) * B;
		for(int j = p; j < n; j++){
			cur = min(cur, a[j]);
			arr[j] = cur + (j - k < 0 ? 0 : arr[j - k]);
		}
		for(int ind: queries[i]){
			int l = L[ind], r = R[ind];
			cur = INF;
			for(int j = l, x = 0; j < p && j <= r; j++){
				cur = min(cur, a[j]);
				if(x == 0) answers[ind] += cur;
				x++;
				if(x == k) x = 0;
			}
			if(p > r) continue;
			// l + j * k
			int total = (r - l) / k + 1;
			int done = (p - 1 - l) / k + 1;
			int lo = done, hi = total;
			while(lo < hi){
				int mid  = (lo + hi) >> 1;
				int m = l + mid * k;
				if(st.get(p, m) == st.get(l, m)) hi = mid;
				else lo = mid + 1;
			}
			// done .. lo - 1
			answers[ind] += (lo - done) * 1LL * st.get(l, p - 1);
			// lo ... total - 1
			answers[ind] += arr[l + k * (total - 1)] - (l + k * (lo - 1) < 0 ? 0 : arr[l + k * (lo - 1)]);
		}
	}
	for(ll x: answers) cout << x << endl;
}