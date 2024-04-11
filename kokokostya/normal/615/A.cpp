#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n, m;
	cin >> n >> m;
	vector<int> used(m);
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		for (int j = 0; j < a; j++) {
			int b;
			cin >> b;
			used[b - 1] = 1;
		}
	}
	bool is = 1;
	for (int i = 0; i < m; i++) {
		if (!used[i]) { is = 0; }
	}
	if (is) { cout << "YES"; }
	else { cout << "NO"; }

	return 0;
}