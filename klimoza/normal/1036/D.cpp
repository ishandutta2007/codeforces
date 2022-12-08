#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	ios_base::sync_with_stdio(false);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	vector<int> b(m);
	for (int i = 0; i < m; i++) {
		cin >> b[i];
	}
	int l = 0;
	int r = 0;
	long long int suml = a[l];
	long long int sumr = b[r];
	int leng = 0;
	bool fl = true;
	while ((l < (n - 1)) || (r < (m - 1))) {
		//cout << suml << " " << sumr << " " << l << "    " << r << " " << leng << "\n";
		if (suml == sumr) {
			leng++;
			suml = 0;
			sumr = 0;
		}
		if (suml < sumr) {
			if (l >= (n - 1)) {
				fl = false;
				break;
			}
			l++;
			suml += a[l];
		}
		else {
			if (r >= (m - 1)) {
				fl = false;
				break;
			}
			r++;
			sumr += b[r];
		}
	}
	if (suml != sumr || !fl) {
		cout << -1 << "\n";
	}
	else {
		if (suml != 0) leng++;
		cout << leng << "\n";
	}
	//system("pause");
	return 0;
}