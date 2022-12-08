#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <deque>
#include <cmath>

using namespace std;


bool comp(int x, int y) {
	if (x > y) return true;
	return false;
}



int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	int ind_max = 0;
	int ind_min = 1;
	vector<int> used(n);
	int ans = 0;
	while (ind_max < n and ind_min < n) {
		if (ind_max == ind_min) {
			ind_min++;
		}
		else if (used[ind_max] == 1) {
			ind_max++;
		} else if(a[ind_max] < a[ind_min]){
			used[ind_max] = 1;
			ind_max++;
			ind_min++;
			ans++;
		}
		else {
			ind_min++;
		}
	}
	cout << ans << "\n";
	//system("pause");
	return 0;
}