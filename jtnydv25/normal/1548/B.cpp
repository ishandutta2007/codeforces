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
		if(i > j) return 0LL;
		int k = floorlog[j - i + 1];
		return func(arr[k][i], arr[k][j - (1 << k) + 1]);
	}
};
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<ll> a(n);
		for(ll & x : a) cin >> x;
		if(n == 1){
			cout << 1 << endl;
			continue;
		}
		vector<ll> T(n - 1);

		for(int i = 0; i + 1 < n; i++){
			T[i] = abs(a[i] - a[i + 1]);
		}

		sparse_table<ll> st(T, [](ll x, ll y){return __gcd(x, y);});
		int j = -1;
		int ans = 0;
		// trace(T);
		for(int i = 0; i + 1 < n; i++){
			j = max(j, i - 1);
			while(j + 2 < n && st.get(i, j + 1) != 1)j++;
			ans = max(ans, j - i + 1);
			// trace(i, j);
		}
		cout << ans + 1 << endl;
	}
}