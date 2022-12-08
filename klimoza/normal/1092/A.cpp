#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

typedef long long ll;

const ll INF = 1e18;

int main() {
	int t;
	cin >> t;
	for (int cnt = 0; cnt < t; cnt++) {
		int n, k;
		cin >> n >> k;
		int h = n / k;
		int f = n % k;
		for (int i = 0; i < h; i++) {
			for (int j = 0; j < k; j++) {
				cout << char(j + 'a');
			}
		}
		for (int i = 0; i < f; i++) {
			cout << char(i + 'a');
		}
		cout << endl;
	}
	//system("pause");
	return 0;
}