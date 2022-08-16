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
#endif

const ll INF = 1LL<<60;
ll power(int n){
	return n < 60 ? (1LL << n) : INF;
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n, W; cin >> n >> W;
		vector<int> a(n);
		for(int & x : a){
			cin >> x;
		}
		sort(all(a));
		reverse(all(a));
		int cnt = 1;
		multiset<ll> widths = {-W};
		for(int i = 0; i < n; i++){
			if(widths.empty()) widths.insert(-W), cnt++;
			if(-*widths.begin() < a[i]) widths.insert(-W), cnt++;
			ll w = -*widths.begin();
			widths.erase(widths.find(-w));
			if(w != a[i]) widths.insert(-w + a[i]);
		}
		cout << cnt << endl;
	}
}