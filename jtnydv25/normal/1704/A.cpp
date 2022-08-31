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
#define endl '\n' // remove in interactive
#endif

void solve(){
	int n, m; cin >> n >> m;
		string a, b;
		cin >> a >> b;
		for(int i = n - m + 1; i < n; i++) if(a[i] != b[i - n + m]){
			cout << "NO" << endl;
			return;
		}
		for(int i = 0; i <= n - m; i++){
			if(a[i] == b[0]){
				cout << "YES" << endl;
				return;
			}
		}
		cout << "NO" << endl;
}
int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		solve();		
	}
}