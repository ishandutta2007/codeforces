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
    vector<ll> a(n);
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    ll dec = 0;
    vector<ll> d(n - 1);
    for(int i = 0; i < n - 1; i++) {
    	if(a[i + 1] > a[i]) {
    		dec += a[i + 1] - a[i];
    	}
    	d[i] = a[i + 1] - a[i];
    }
    if(a[0] + dec > 0) {
		cout << (a[0] + dec - 1) / 2 + 1 << '\n';
	} else {
		cout << -(abs(a[0] + dec) / 2) << '\n';
	}
    int q;
    cin >> q;
    for(int i = 0; i < q; i++) {
    	int l, r, x;
    	cin >> l >> r >> x;
    	--l;
    	--r;
    	if(l == 0) {
    		a[0] += x;
    	}
    	if(r != n - 1) {
    		if(d[r] > 0) {
    			dec -= d[r];
    		}
    		d[r] -= x;
    		if(d[r] > 0) {
    			dec += d[r];
    		}
    	}
    	if(l != 0) {
    		if(d[l - 1] > 0) {
    			dec -= d[l - 1];
    		}
    		d[l - 1] += x;
    		if(d[l - 1] > 0) {
    			dec += d[l - 1];
    		}
    	}
    	if(a[0] + dec > 0) {
    		cout << (a[0] + dec - 1) / 2 + 1 << '\n';
    	} else {
    		cout << -(abs(a[0] + dec) / 2) << '\n';
    	}
    }
}