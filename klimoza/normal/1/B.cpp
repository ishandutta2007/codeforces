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
	int k;
	cin >> k;
	string st;
	for (int i = 0; i < k; i++) {
		cin >> st;
		int typ = 1;
		int n = st.size();
		for (int j = 1; j < st.size(); j++) {
			if (st[j] == 'C' && st[j - 1] <= '9' && st[j - 1] >= '0') {
				typ = 2;
				break;
			}
		}
		if (typ == 1) {
			int num1 = 0;
			int num2 = 0;
			for (int j = 0; j < n; j++) {
				if (st[j] >= 'A' && st[j] <= 'Z') {
					num1 *= 26;
					num1 += st[j] - 'A' + 1;
				}
				else {
					num2 *= 10;
					num2 += st[j] - '0';
				}
			}
			cout << "R" << num2 << "C" << num1 << "\n";
		}
		else {
			bool fl = false;
			int num1 = 0;
			int num2 = 0;
			for (int j = 1; j < n; j++) {
				if (st[j] == 'C') {
					fl = true;
				}
				else if (!fl) {
					num1 *= 10;
					num1 += st[j] - '0';
				}
				else {
					num2 *= 10;
					num2 += st[j] - '0';
				}
			}
			string stan = "";
			while (num2 > 0) {
				num2--;
				stan = (char)((num2 % 26) + 'A') + stan;
				num2 /= 26;
			}
			cout << stan << num1 << "\n";
		}
	}
	//system("pause");
	return 0;
}