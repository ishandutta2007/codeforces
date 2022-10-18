
 #include <bits/stdc++.h>
 #define int long long
using namespace std;
 
main() {
	int n, k;
	cin >> n >> k;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
	}
	int l = 0; int r = k+1;
	while(r - l > 1){
		int mid = (r + l) / 2;
		if (mid * (mid + 1) <= 2*k){
			l = mid;
		}
		else{
			r = mid;
		}
	}
	l++;
		if (k != l * (l-1) / 2){
		cout << a[k-1-(l * (l - 1) / 2)];
	}
	else{
		cout << a[l-2];
	}
}