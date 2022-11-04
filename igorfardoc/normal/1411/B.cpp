#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;

bool is_good(ll x) {
	ll now = x;
	while(now) {
		int here = now % 10;
		if(here != 0 && x % here != 0) {
			return false;
		}
		now /= 10;
	}
	return true;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin >> t;
    while(t--) {
    	ll x;
    	cin >> x;
    	while(!is_good(x)) {
    		++x;
    	}
    	cout << x << '\n';
    }
}