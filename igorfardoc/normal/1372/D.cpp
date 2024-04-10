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
    int n;
    cin >> n;
    vi a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    vector<ll> pref1(n + 1, 0), pref2(n + 1, 0);
    for(int i = 1; i <= n; i++) {
    	pref1[i] = pref1[i - 1];
    	pref2[i] = pref2[i - 1];
    	if(i % 2 == 1) {
    		pref2[i] += a[i - 1];
    	} else {
    		pref1[i] += a[i - 1];
    	}
    }
    ll res = 0;
    for(int i = 0; i < n; i++) {
    	if(i % 2 == 0) {
    		res = max(res, pref1[i] + pref2[n] - pref2[i]);
    	} else {
    		res = max(res, pref2[i] + pref1[n] - pref1[i]);
    	}
    }
    cout << res;
}