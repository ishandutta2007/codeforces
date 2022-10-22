#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0;i < n;i++){
		cin >> a[i];
	}
	sort(a.begin(),a.end());
	int  l = 0,r  = 1e10;
	while(l + 1 < r){
		int m = (l + r) / 2;
		bool f =true;
		int sum = 0, k1 = 0;
		for(int i = 0;i < n;i++){
			if(a[i] > m){
				break;
			}
			sum += a[i];
			k1++;
		}
		int z = m * k1;
		if(z - sum > k){
			f = false;
		}
		if(f){
			l = m;
		}
		else{
			r = m;
		}
	}
	int mini = l;
	int b = k;
	for(int i = 0;i < n;i++){
		if(a[i] < mini){
			b -= mini - a[i];
			a[i] = mini;
		}
	}
	for(int i = 0;i < b;i++){
		a[i] += 1;
	}
	sort(a.begin(),a.end());
	l = -1,r  = 1e10;
	while(l + 1 < r){
		int m = (l + r) / 2;
		bool f =true;
		int sum = 0, k1 = 0;
		for(int i = n - 1;i > -1;i--){
			if(a[i] < m){
				break;
			}
			sum += a[i];
			k1++;
		}
		int z = m * k1;
		if(sum - z > k){
			f = false;
		}
		if(f){
			r = m;
		}
		else{
			l = m;
		}
	}
	int maxi = l + 1;
	b = k;
	for(int i = n - 1;i > -1;i--){
		if(a[i] > maxi){
			b -= abs(maxi - a[i]);
			a[i] = maxi;
		}
	}
	for(int i = n - 1;i > -1 && b > 0;i--){
		b--;
		a[i] -= 1;
	}
	sort(a.begin(),a.end());

	cout << a[n - 1] - a[0];
}