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

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n);
		for(int & x : a) cin >> x;
		vector<int> oddpos(n / 2), evenpos((n + 1) / 2);
		for(int i = 0; i < n / 2; i++) oddpos[i] = 2 * i + 1;
		for(int i = 0; i < (n + 1) / 2; i++) evenpos[i] = 2 * i;
		vector<int> odd, even;
		for(int i = 0; i < n; i++){
			if(a[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
		const ll INF = 1000000000 * 1LL * 1000000000;
		ll ans = INF;
		if(sz(odd) == sz(oddpos) && sz(even) == sz(evenpos)){
			ll sum = 0;
			for(int i = 0; i < sz(oddpos); i++) sum += abs(oddpos[i] - odd[i]);
			ans = min(ans, sum);
		}

		if(sz(even) == sz(oddpos) && sz(odd) == sz(evenpos)){
			ll sum = 0;
			for(int i = 0; i < sz(even); i++) sum += abs(oddpos[i] - even[i]);
			ans = min(ans, sum);
		}

		cout << (ans  == INF ? -1 : ans) << endl;
	}
}