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
	int n, s;
	cin >> n >> s;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) cin >> b[i];
	if (a[0] == 0 || (a[s - 1] == 0 && b[s - 1] == 0)) {
		cout << "NO\n";
	}
	else {
		if (a[s - 1] == 1) {
			cout << "YES\n";
		}
		else {
			bool fl = false;
			for (int i = s; i < n; i++) {
				if (a[i] + b[i] == 2) {
					fl = true;
				}
			}
			if (fl) {
				cout << "YES\n";
			}
			else {
				cout << "NO\n";
			}
		}
	}
	//system("pause");  
	return 0;
}