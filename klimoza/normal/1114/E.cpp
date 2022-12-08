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

int gcd(int a, int b) {
	if (!b) return a;
	return gcd(b, a % b);
}


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	int n;
	cin >> n;
	int all = 60;
	int l = -1;
	int r = 1e9;
	while (r - l > 1) {
		int mid = (r + l) / 2;
		cout << "> " << mid << endl;
		int ans;
		cin >> ans;
		if (ans == -1) return 1;
		if (!ans) r = mid;
		else l = mid;
		all--;
	}
	l = r;
	int gc = 0;
	vector<int> p(n);
	for (int i = 0; i < n; i++) p[i] = i + 1;
	shuffle(p.begin(), p.end(), mt19937(random_device()()));
	vector<int> f;
	int t;
	for (int i = 0; i < min(n, all); i++) {
		cout << "? " << p[i] << endl;
		cin >> t;
		f.push_back(t);
	}
	sort(f.begin(), f.end());
	gc = r - f[0];
	for (int i = 1; i < f.size(); i++) {
		gc = gcd(gc, f[i] - f[i - 1]);
	}
	cout << "! " << l - (n - 1) * gc << " " << gc << endl;
	//system("pause");
	return 0;
}