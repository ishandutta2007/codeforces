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
		map<int, int> freq;
		for(int& x: a){
			cin >> x;
			freq[x]++;
		}
		vector<int> cnt(n + 1);
		for(auto it: freq) cnt[it.second]++;
		// trace(cnt);
		int ans = 0;
		for(int i = n; i >= 2; i--){
			ans += cnt[i];
		}
		ans += (cnt[1] + 1) / 2;
		cout << ans << endl;
	}
}