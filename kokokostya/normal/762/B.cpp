#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int m;
	cin >> m;
	vector<int> arra, arrb;
	while (m--) {
		int val;
		string l;
		cin >> val >> l;
		if (l[0] == 'U')
			arra.push_back(val);
		else
			arrb.push_back(val);
	}
	sort(arra.begin(), arra.end());
	sort(arrb.begin(), arrb.end());
	int ans = min(a, int(arra.size())) + min(b, int(arrb.size())) + min(max(0, int(arra.size()) - a) + max(0, int(arrb.size()) - b), c);
	long long res = 0;
	int i = 0, j = 0;
	c = min(max(0, int(arra.size()) - a) + max(0, int(arrb.size()) - b), c);
	a = min(a, int(arra.size()));
	b = min(b, int(arrb.size()));
	while ((i < arra.size() || j < arrb.size()) && (a || b || c)) {
		if (i != arra.size() && a) {
			res += arra[i];
			i++;
			a--;
		}
		else {
			if (j != arrb.size() && b) {
				res += arrb[j];
				j++;
				b--;
			}
			else {
				if (i == arra.size()) {
					c--;
					res += arrb[j];
					j++;
				}
				else {
					if (j == arrb.size()) {
						c--;
						res += arra[i];
						i++;
					}
					else {
						if (arra[i] > arrb[j]) {
							res += arrb[j];
							j++;
							c--;
						}
						else {
							res += arra[i];
							i++;
							c--;
						}
					}
				}
			}
		}
	}

	cout << ans << ' ' << res;
	return 0;
}