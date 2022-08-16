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

int ask(int w){
	cout << "? " << w << endl;
	fflush(stdout);
	int h; cin >> h;
	return h;
}

int main(){
	// ios_base::sync_with_stdio(false); 
	// cin.tie(NULL); // Remove in interactive problems
	int n; cin >> n;
	int lo = 1, hi = 2001 * n;
	while(lo < hi){
		int mid = (lo + hi) / 2;
		int z = ask(mid);
		if(z == 1) hi = mid;
		else lo = mid + 1;
	}
	int val = lo;
	ll ans = val;
	for(int h = 2; h <= n; h++){
		int w = (val - 1) / h;
		if(w != 0){
			int z = ask(w);
			if(z != 0)
				ans = min(ans, w * 1LL * z);
		}
	}
	cout << "! " << ans << endl;
	fflush(stdout);
}