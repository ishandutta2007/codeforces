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
    int n, k;
    cin >> n >> k;
    ++k;
    vi a(n);
    ll p = 0;
    vi b;
    for(int i = 0; i < n; i++) {
    	cin >> a[i];
    }
    sort(a.begin(), a.end());
    ll sumnow = 0;
    ll sum = 0;
    ll sumnow1 = 0;
    for(int i = n - 1; i >= 0; i--) {
    	if(a[i] >= 0) {
    		sumnow1 += sum;
    		sum += a[i];
    		sumnow += sum;
    	} else {
    		b.push_back(a[i]);
    	}
    }
    reverse(b.begin(), b.end());
    ll ans = -4000000000000000000ll;
    if(b.size() == 0) {
    	cout << sumnow1;
    	return 0;
    }
    ll all1 = sumnow + sum * (((int)b.size() - 1) / k);
    for(int i = 0; i < b.size(); i++) {
    	all1 += (ll)(i / k) * b[i];
    }
    ans = all1;
    for(int i = b.size() - 1; i >= 0; i--) {
    	if(i == b.size() - 1 || (i + 1) % k == 0) {
    		sum += b[i];
    		continue;
    	}
    	all1 += sum;
    	sum += b[i];
    	ans = max(ans, all1);
    }
    cout << ans << '\n';

}