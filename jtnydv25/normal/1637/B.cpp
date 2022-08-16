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
		ll ans = 0;
		for(int i = 0; i < n; i++){
			int l = i + 1;
			ans += l * (n - l + 1);
			cin >> a[i];
			if(a[i] == 0) ans += (i + 1) * (n - i);
		}
		cout << ans << endl;
	}
}