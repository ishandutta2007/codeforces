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
		int n;
		string a, b; cin >> n >> a >> b;
		int ones_a = 0, ones_b = 0;
		vector<int> vals(4);
		for(int i = 0; i < n; i++){
			if(a[i]=='1') ones_a++;
			if(b[i] == '1') ones_b++;
			vals[(a[i] == '1') * 2 + (b[i] == '1')]++;
		}

		const int INF = 1<< 29;
		int ans = INF;

		int flips = vals[1] + vals[2];
		// even number of flips
		if(ones_a == ones_b && vals[1] == vals[2]){
			ans = flips;
		}
		
		if(ones_a + ones_b == n + 1 && vals[3] == vals[0] + 1){
			ans = min(ans, n - flips);
		}
		cout << (ans == INF ? -1 : ans) << endl;
	}
}