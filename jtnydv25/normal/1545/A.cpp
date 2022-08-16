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
const int N = 100005;
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<vector<int>> num(N, vector<int>(2));
		for(int i = 0; i < n; i++){
			int c; cin >> c;
			num[c][i % 2]++;
		}
		int j = 0;
		bool ok = true;
		for(int i = 0; i < N; i++){
			int k = num[i][0] + num[i][1];
			int num_odd = k / 2, num_even = k - num_odd;
			if(j & 1){
				swap(num_odd, num_even);
			}
			if(num_odd != num[i][1] && num_even != num[i][0]){
				ok = false;
			}
			j = (j + k) & 1;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}