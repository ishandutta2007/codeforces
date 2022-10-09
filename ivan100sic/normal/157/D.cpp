#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int a[100005], n, m;
int da[100005], ne[100005];
int sumne, sumda;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		if (a[i] < 0) {
			ne[-a[i]]++;
			sumne++;
		}
		else {
			da[a[i]]++;
			sumda++;
		}
	}

	set<int> mozda;

	for (int i = 1; i <= n; i++) {
		int t = da[i] + sumne - ne[i];
		if (t == m) {
			mozda.insert(i);
		}
	}

	for (int i = 1; i <= n; i++) {
		if (a[i] > 0) {
			if (mozda.size() == 1 && mozda.count(a[i])) {
				cout << "Truth\n";
			}
			else if (mozda.size() > 1 && mozda.count(a[i])) {
				cout << "Not defined\n";
			}
			else {
				cout << "Lie\n";
			}
		}
		else {
			if (mozda.size() == 1 && mozda.count(-a[i])) {
				cout << "Lie\n";
			}
			else if (mozda.size() > 1 && mozda.count(-a[i])) {
				cout << "Not defined\n";
			}
			else {
				cout << "Truth\n";
			}
		}
	}
}