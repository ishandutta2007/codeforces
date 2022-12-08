#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-6;
ll mod = 1e9 + 7;

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);

	int n;
	cin >> n;
	vector<int> a(n + 1);
	int cnt = 1;
	for (int i = 2; i <= n; i++) {
		bool fl = false;
		for (int j = i; j <= n; j += i) {
			if (!a[j]) {
				fl = true;
				a[j] = cnt;
			}
		}
		if (fl) cnt++;
	}
	for (int i = 2; i <= n; i++) cout << a[i] << " ";
	cout << endl;
	//system("pause");
	return 0;
}