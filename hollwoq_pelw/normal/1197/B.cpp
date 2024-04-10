#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int m = 0;
	for (int i = 0; i < n; i++) if (a[i] > a[m]) m = i;
	for (int i = m; i > 0; i--){
		if (a[i] < a[i - 1]) {
			cout << "NO";
			return 0;
		}
	}
	for (int i = m; i < n - 1; i++) {
		if (a[i] < a[i + 1]) {
			cout << "NO";
			return 0;
		}
	}
	cout << "YES";
 
	return 0;
}