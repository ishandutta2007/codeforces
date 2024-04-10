#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fs first
#define sc second
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	int a[5];
	cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
	int maxi = 0;
	int n = 5;
	for (int i = 0; i < n-1; i++){
		for (int j = i+1; j < n; j++){
			maxi = max(maxi, 2*(a[i] == a[j]) * a[i]);
		}
	}
	
	for (int i = 0; i < n-2; i++){
		for (int j = i+1; j < n-1; j++){
			for (int k = j+1; k < n; k++){
				maxi = max(maxi, 3*(a[i] == a[j] && a[j] == a[k]) * a[i]);
			}
		}
	}
	
	maxi *= -1;
	
	for (int i = 0; i < n; i++){
		maxi += a[i];
	}
	
	cout << maxi;
}