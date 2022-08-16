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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int & x: a) cin >> x;
		bool ok = false;
		for(int i = 0; i + 1 < n; i++) if(a[i] > a[i + 1]){
			ok = true;
		}
		cout << (ok ? "YES" : "NO") << endl;
	}
}