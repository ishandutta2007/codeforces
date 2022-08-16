#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define pii pair<int, int>
#define all(c) ((c).begin()), ((c).end())
#define sz(x) ((int)(x).size())

#ifdef LOCAL
#include <print.h>
#else
#define trace(...) // remove in interactive
#define endl '\n'
#endif

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		set<int> st;
		map<int, int> freq;
		for(int i = 0; i < n; i++){
			int x; cin >> x;
			freq[x]++;
		}
		int ans = freq.find(0) != freq.end();
		for(int i = 1; i <= 100; i++){
			int u = freq[i], v = freq[-i];
			if(!u && !v) continue;
			if(u && v) ans+=2;
			else if(max(u, v) > 1) ans+=2;
			else ans++;
		}
		cout << ans << endl;
	}
}