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

int num(int i, int L){
	int ret = (L >> (i + 1)) << i;
	int u = L % (1 << (i + 1));
	return ret + max(0, u - (1 << i) + 1);
}

int main(){
	ios_base::sync_with_stdio(false); 
	cin.tie(NULL); // Remove in interactive problems
	int t; cin >> t;
	// cerr << num(1, 8) << " " << num(1, 1) << endl;
	while(t--){
		int L, R; cin >> L >> R;
		int mx = 0;
		for(int i = 0; i < 20; i++) mx = max(mx, num(i, R) - num(i, L - 1));
		cout << R - L + 1 - mx << endl;
	}
}