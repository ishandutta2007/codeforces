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
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	int k = 0;
	for (int i = 1; i < n - 1; i++) {
		if (!a[i] && a[i - 1] && a[i + 1]) {
			a[i + 1] = 0;
			k++;
		}
	}
	cout << k << "\n";
	//system("pause");  
	return 0;
}