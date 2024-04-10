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
	int maxi = 0;
	int cnt = 0;
	int cur = 1;
	cin >> a[0];
	for (int i = 1; i < n; i++) {
		cin >> a[i];
		if (a[i] == a[i - 1]) cur++;
		else {
			if (a[i - 1] > maxi || (a[i - 1] == maxi && cur > cnt)) {
				maxi = a[i - 1];
				cnt = cur;
			}
			cur = 1;
		}
	}
	if (a[n - 1] > maxi || (a[n - 1] == maxi && cur > cnt)) {
		maxi = a[n - 1];
		cnt = cur;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}