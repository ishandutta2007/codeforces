#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;


int main() {
	int n, m, k;
	cin >> n >> m >> k;
	int cur = k;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	cur = k - a[n - 1];
	m--;
	int ans = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (m == -1) {
			//cout << i << "\n";
			ans = n - i - 2;
			break;
		}
		if (a[i] <= cur) {
			cur -= a[i];
		}
		else{
			m--;
			cur = k - a[i];
		}
	}
	if (ans == 0 && m == -1) {
		cout << n - 1 << "\n";
	} else if (ans == 0) {
		cout << n << "\n";
	}
	else {
		cout << ans << "\n";
	}
	//system("pause");  
	return 0;
}