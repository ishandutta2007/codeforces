#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	int sum = 0;
	double h;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		sum += a[i];
	}
	h = (double)sum / n;
	sort(a.begin(), a.end());
	int ind = 0;
	int count = 0;
	while (h < 4.5) {
		sum -= a[ind];
		sum += 5;
		h = (double)sum / n;
		ind++;
		count++;
	}
	cout << count << "\n";
	//system("pause");
	return 0;
}