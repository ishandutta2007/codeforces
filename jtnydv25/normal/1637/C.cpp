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
		for(int& x: a) cin >> x;
		if(*max_element(a.begin() + 1, a.end() - 1) == 1){
			cout << "-1" << endl;
			continue;
		}
		if(n == 3 && a[1] % 2 == 1){
			cout << "-1" << endl;
			continue;
		}
		ll ans = 0;
		for(int i = 1; i + 1 < n; i++) ans += (a[i] + 1) / 2;
		cout << ans << endl;
	}
}