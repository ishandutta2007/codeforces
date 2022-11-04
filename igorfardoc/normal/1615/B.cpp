#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;



int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	#ifdef _FILE
    	freopen("input.txt", "r", stdin);
    	freopen("output.txt", "w", stdout);
	#endif
    vvi pref(20, vi(200001, 0));
    for(int i = 1; i <= 200000; i++) {
    	for(int j = 0; j < 20; j++) {
    		pref[j][i] = pref[j][i - 1];
    		if((i >> j) & 1) {
    			++pref[j][i];
    		}
    	}
    }
    int t;
    cin >> t;
    while(t--) {
    	int l, r;
    	cin >> l >> r;
    	int mx = 0;
    	for(int i = 0; i < 20; i++) {
    		int am = pref[i][r] - pref[i][l - 1];
    		mx = max(am, mx);
    	}
    	cout << r - l + 1 - mx << '\n';
    }
}