#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>

using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int> a(n + 1);
	vector<int> time(n + 1);
	int ind = 1;
	int t;
	for (int i = 1; i <= n; i++) {
		cin >> t;
		if (a[time[t]] == t) {
			time[i] = time[t];
			a[time[i]] = i;
		}
		else {
			time[i] = ind;
			a[ind] = i;
			ind++;
		}
	}
	cout << ind << "\n";
	//system("pause");
	return 0;
}