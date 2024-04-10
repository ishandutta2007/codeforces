#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	int positive=0, negative=0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		if (k > 0) positive++;
		else if (k < 0) negative++;
	}
	double m = n*1.00/2;
	m = ceil(m);
	if (positive >= m) cout << "1";
	else if (negative >= m) cout << "-1";
	else cout << "0";
	return 0;
}