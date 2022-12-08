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

	int n;
	cin >> n;
	vector<int> a(n);
	int mini = 1e9;
	int ind = -1;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] < mini) {
			mini = a[i];
			ind = i;
		}
		sum += a[i];
	}
	int cur = sum;
	for (int i = 0; i < n; i++) {
		if (i == ind) continue;
		for (int j = 1; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				//cout << a[i] << " " << j << " " << mini << endl;
				if (cur - a[i] - mini + (a[i]) / j + mini * j < sum) sum = cur - a[i] - mini + (a[i]) / j + mini * j;
				if (cur - a[i] - mini + j + mini * (a[i] / j) < sum) sum = cur - a[i] - mini + j + mini * (a[i] / j);
			}
		}
	}
	cout << sum << endl;
	//system("pause");
	return 0;
}