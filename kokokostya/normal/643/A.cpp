#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> a;
vector <int> temp;
vector <int> ans;

int main() {
	int n;
	cin >> n;
	a.resize(n);
	ans.resize(n, 0);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		a[i]--;
		temp.clear();
		temp.resize(n, 0);
		int mx, mxc;
		mx = 0;
		mxc = -1;
		for (int j = i; j >= 0; j--) {
			temp[a[j]]++;
			if (temp[a[j]] > mx || (temp[a[j]] == mx && mxc > a[j])) {
				mx = temp[a[j]];
				mxc = a[j];
			}
			ans[mxc]++;
		}
	}
	for (int i = 0; i < n; i++)
		cout << ans[i] << ' ';
	return 0;
}