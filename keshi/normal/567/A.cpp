#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[100010];
	cin >> n;
	for (int i=0; i<n; i++){
		cin >> a[i];
	}
	cout << a[1]-a[0] << ' ' << a[n-1]-a[0] << '\n';
	for (int i=1 ;i<n-1; i++){
		cout << min(a[i]-a[i-1], a[i+1]-a[i]) << ' ';
		cout << max( a[n-1]-a[i] , a[i]-a[0]) << '\n';
	}
	cout << a[n-1]-a[n-2] << ' ' << a[n-1]-a[0];
}