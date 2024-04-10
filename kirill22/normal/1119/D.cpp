#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	if (n == 1){
		int q;
		cin >> q;
		while(q--){
			int l,r;
			cin >> l >> r;
			cout << r - l + 1 << " ";
			
		}
		return 0;
	}
	vector<int> b(n-1);
	for(int i = 0;i < n-1;i++){
		b[i] = a[i+1] - a[i];
	}
	sort(b.begin(),b.end());
	int pref[n-1];
	pref[0] = b[0];
	for(int i=1;i<n-1;i++){
		pref[i] = pref[i-1] + b[i];
	}
	
	
	int q;
	cin >> q;
	while(q--){
		int l,r;
		cin >> l >> r;
		r -= l;
		int ans = 0;
		ans = n * ( r + 1);
		int L = 0,R = n;
		if (b[0] > r){
			cout << ans <<" ";
			continue;
		}
		if (b[n-2] <= r){
			L = n-2;
		}
		else{
		while(L + 1 <R){
			int mid = (L+R)/2;
			if (b[mid] <= r){
				L = mid;
			}
			else{
				R = mid;
			}
		}
		}
		ans -= (r + 1)*(L + 1);
		ans += pref[L];
		cout << ans << " ";
	}
}