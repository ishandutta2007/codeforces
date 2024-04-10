#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
	int n;
	cin >> n;
	vector<long double> a(n);
	int sum = 0;
	for(int i = 0;i < n;i++) {
		cin >> a[i];
		int y  = a[i];
		if(a[i] == y) {
			sum += y;
		}
		else if(a[i] < 0) {
			sum += y - 1;
		}
		else {
			sum += y;
		}
	}
	//cout << sum << endl;
	int i = 0;
	while(sum != 0 && i < n) {
		if(a[i] != (int) a[i]) {
			if(sum < 0) {
				if(a[i] < 0) {
					a[i] = (int) a[i];
					sum += 1;
				}
				else {
					a[i] = (int) a[i] + 1;
					sum += 1;
				}
			}
			else {
				if(a[i] < 0) {
					a[i] = (int) a[i] - 1;
					sum -= 1;
				}
				else {
					a[i] = (int) a[i];
					sum -= 1;
				}
			}
		}
		i++;
	}
	for(int i = 0;i < n;i++) {
		if(a[i] == (int ) a[i]) {
			cout << a[i] << " ";
		}
		else {
			int y  = a[i];
			if(a[i] < 0) {
				cout << y - 1 << " ";
			}
			else {
				cout << y << " ";
			}
		}
	}
}