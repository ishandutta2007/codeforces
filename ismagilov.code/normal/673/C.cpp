#include <bits/stdc++.h>
#define int long long
using namespace std;

main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		a[i]--;
	}
	vector<int> res(n);
	vector<int> kol(n);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			kol[j] = 0;
		}
		int maxi = 0;
		int max1 = 1000000000;
		for (int j = i; j < n; j++){
			kol[a[j]]++;
			if (kol[a[j]] > maxi || (kol[a[j]] == maxi && a[j] < max1)){
				max1 = a[j];
				maxi = kol[a[j]];
				
			}
			res[max1]++;
		}
		
	}
	for (int i = 0; i < n; i++){
		cout << res[i] << ' ';
	}
}