#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>
#include <math.h>
#include <random>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n, x;
	cin >> n >> x;
	vector<int> ans;
	int lost = n;
	vector<int> used(1e6 + 1);
	int k = x;
	int f = 1;
	if (lost == 1) {
		ans.push_back(x);
		lost--;
	}
	while (lost != 0) {
		if (lost == 3 && f == k) {
			f++;
		} else if (lost == 2) {
			for (int i = 0; i <= 1e6; i++) {
				if (!used[i] && !used[k ^ i] && i != (k ^ i)) {
					ans.push_back(i);
					ans.push_back(k ^ i);
					lost = 0;
					break;
				}
			}
			if (lost) {
				cout << "NO\n";
				return 0;
			}
		}
		else {
			if (used[f]) {
				f++;
			}
			else {
				k ^= f;
				ans.push_back(f);
				used[f] = true;
				f++; 
				lost--;
			}
		}
	}
	cout << "YES\n";
	for (int i : ans) cout << i << " ";
	cout << endl;
	//system("pause");
	return 0;
}