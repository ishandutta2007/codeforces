#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main() {
	string str;
	cin >> str;
	int prec = 0;
	vector<char> vc; vector<int> vl;
	for (int i = 1; i <= str.size(); ++i) {
		if (i == str.size() || str[i - 1] != str[i]) {
			vc.push_back(str[i - 1]);
			vl.push_back(i - prec);
			prec = i;
		}
	}
	if (vc.size() % 2 == 0) {
		cout << 0 << endl;
	}
	else {
		int m = vc.size() / 2;
		if (vl[m] <= 1) {
			cout << 0 << endl;
		}
		else {
			bool ok = true;
			for (int i = 0; i < m; ++i) {
				if (vc[i] != vc[vl.size() - i - 1] || vl[i] + vl[vl.size() - i - 1] <= 2) {
					ok = false;
				}
			}
			cout << (ok ? vl[m] + 1 : 0) << '\n';
		}
	}
	return 0;
}