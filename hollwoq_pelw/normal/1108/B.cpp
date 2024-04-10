#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++){
	    cin >> a[i];
	}
	sort(a, a+n, greater<int>());
	int x = a[0], y;
	for (int i = 0; i < n; i++){
	    if (x%a[i]!=0 || a[i]==a[i+1]) {y = a[i]; break;}
	}
	cout << x << ' ' << y;
}