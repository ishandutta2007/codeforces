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
	int n, k;
	cin >> n >> k;
	vector<int> a(101);
	int t;
	int cnt = 0;
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (a[t] == 0) cnt++;
		a[t]++;
		maxi = max(a[t], maxi);
	}
	int all = ceil(maxi / (double)k) * k;
	cout << all * cnt - n << "\n";
	//system("pause");  
	return 0;
}