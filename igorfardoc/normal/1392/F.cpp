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
    int now = -1;
    vector<ll> sum(n + 1, 0);
    for(int i = 1; i < n; i++) {
    	if(now != -1) {
    		ll am = i - now;
    		if(a[i] - am > a[i - 1] + 1) {
    			a[i] -= am;
    			++sum[i - 1];
    			--sum[now];
    			++a[i - 1];
    			now = -1;
    		} else {
    			ll can = a[i] - a[i - 1] - 1;
    			int now1 = now + can;
    			a[i] -= can;
    			++sum[now1];
    			--sum[now];
    			now = now1;
    			continue;
    		}
    	}
    	ll canfull = (a[i] - a[i - 1] - 1) / (i + 1);
    	a[i] -= canfull * i;
    	sum[i] += canfull;
    	sum[0] -= canfull;
    	if(a[i] == a[i - 1] + 1 + canfull) {
    		continue;
    	}
    	ll can = a[i] - a[i - 1] - 1 - canfull;
    	int now1 = can;
    	a[i] -= can;
    	++sum[now1];
    	--sum[0];
    	now = now1;
    }
    auto b = a;
    ll here = 0;
    for(int i = n; i >= 0; i--) {
    	if(i != n) {
    		b[i] = a[i] + here;
    	}
    	here += sum[i];
    }
    for(int i = 0; i < n; i++) {
    	cout << b[i] << ' ';
    }
}