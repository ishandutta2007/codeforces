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
    int t; 
    cin >> t;
    while(t--) {
    	string s;
    	cin >> s;
    	int n = s.size();
    	int q;
    	cin >> q;
    	vi pref(n + 1), pref1(n + 1), pref2(n + 1);
    	pref[0] = 0;
    	pref1[0] = 0;
    	pref2[0] = 0;
    	for(int i = 1; i <= n; i++) {
    		pref[i] = pref[i - 1] + (s[i - 1] == '[' || s[i - 1] == ']');
    		pref1[i] = pref1[i - 1];
    		pref2[i] = pref2[i - 1];
    		if(i % 2 == 1) {
    			pref1[i] += s[i - 1] == '[' || s[i - 1] == ']';
    		} else {
    			pref2[i] += s[i - 1] == '[' || s[i - 1] == ']';
    		}
    	}
    	for(int o = 0; o < q; o++) {
    		int l, r;
    		cin >> l >> r;
    		--l;
    		--r;
    		int am = pref[r + 1] - pref[l];
    		int am1 = am;
    		am1 -= abs(pref1[r + 1] - pref1[l] - (pref2[r + 1] - pref2[l]));
    		cout << am - am1 << '\n';
    	}
    }
}