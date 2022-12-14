#include <bits/stdc++.h>
#define int long long
#define umi(x, y) (x = min(x, y))
#define uma(x, y) (x = max(x, y))
using namespace std;

signed main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t; cin >> t;
	while(t--){
		int n; cin >> n;
		vector<int> a(n), b(n), pa(n), pb(n);
		for(int i = 0; i < n; ++i){
			cin >> a[i];
		}
		for(int i = 0; i < n; ++i){
			cin >> b[i];
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		for(int i = 0; i < n; ++i){
			pa[i] = a[i];
			if(i) pa[i] += pa[i - 1];
			pb[i] = b[i];
			if(i) pb[i] += pb[i - 1];
		}
		int low = 0, high = (int)1e8, mid;
		while(low < high){
			mid = (low + high) >> 1;
			int suma = pa[n - 1] + mid * 100, sumb = pb[n - 1];
			int del = (n + mid) / 4;
			if(del) suma -= pa[min(del - 1, n - 1)];
			if(del > n) suma -= (del - n) * 100;
			if(del > mid) sumb -= pb[del - mid - 1];
			if(suma >= sumb) high = mid;
			else low = mid + 1;
		}
		cout << low << '\n';
	}
	return 0;
}