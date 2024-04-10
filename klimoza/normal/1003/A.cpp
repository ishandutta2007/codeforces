#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	vector<int> f(101);
	int t;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		f[t]++;
		maxi = max(maxi, f[t]);
	}
	cout << maxi << "\n";
	//system("pause");
	return 0;
}