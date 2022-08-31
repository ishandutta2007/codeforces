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
		int n, k; cin >> n >> k;
		vector<int>a(n);
		set<int> st;
		string ans = "NO";
		for(int& x: a){
			cin >> x;
			if(st.count(x + k) || st.count(x - k)){
				ans = "YES";
			}
			st.insert(x);
		}
		cout << ans << endl;
	}
}