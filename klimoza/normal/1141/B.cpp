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
long double eps = 1e-8;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maxi = 0;
	int cur = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) cur++;
		else {
			maxi = max(maxi, cur);
			cur = 0;
		}
	}
	int pref = 0;
	int suff = 0;
	for (int i = 0; i < n; i++) {
		if (a[i]) pref++;
		else break;
	}
	for (int i = n - 1; i >= 0; i--) {
		if (a[i]) suff++;
		else break;
	}
	maxi = max(maxi, suff + pref);
	cout << maxi << endl;
	//system("pause");
	return 0;
}