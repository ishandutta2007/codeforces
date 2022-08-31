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
		vector<int> a(n), b(n);
		for(int& x: b) cin >> x;
		for(int& x: a) cin >> x;
		vector<pair<int, int>> vals;
		for(int i = 0; i < n;){
			int j = i;
			while(j < n && a[j] == a[i]) j++;
			vals.push_back({a[i], j - i - 1});
			i = j;
		}

		reverse(all(vals));
		string ans = "YES";
		vector<int> cnt(n + 1);
		int j = 0;
		for(int i = n - 1; i >= 0; i--){
			if(j < sz(vals) && vals[j].first == b[i]){
				cnt[vals[j].first] += vals[j].second;
				j++;
			} else{
				if(cnt[b[i]] == 0){
					ans = "NO";
					break;
				}
				cnt[b[i]]--;
			}
		}
		cout << ans << endl;
	}
}