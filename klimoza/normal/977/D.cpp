#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<long long int> a;
vector<long long int> ans;

void perebor(vector<long long int> prefix, int siz, int cur, vector<int> used) {
	prefix.push_back(a[cur]);	
	used[cur] = 1;
	if (siz == n) {
		ans = prefix;
	}
	else {
		bool fl3 = false;
		bool fl2 = false;
		for (int i = 0; i < n; i++) {
			if (ans.size() != 0) return;
			if (fl3 == false and a[i] == (double)a[cur] / 3 and used[i] == 0) {
				perebor(prefix, siz + 1, i, used);
			}
			if (fl2 == false and a[i] == a[cur] * 2 and used[i] == 0) {
				perebor(prefix, siz + 1, i, used);
			}
		}
	}
}


int main() {
	cin >> n;
	a.resize(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	vector<long long int> prefix;
	vector<int> used(n);
	for (int i = 0; i < n; i++) {
		perebor(prefix, 1, i, used);
	}
	for (int i = 0; i < n; i++) cout << ans[i] << " ";
	//system("pause");
	return 0;
}