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
	
	int n, m;
	cin >> n >> m;
	if (m % n) cout << -1 << endl;
	else {
		int cnt = 0;
		int po = m / n;
		while (!(po % 2)) {
			po /= 2;
			cnt++;
		}
		while (!(po % 3)) {
			po /= 3;
			cnt++;
		}
		if (po == 1) {
			cout << cnt << endl;
		}
		else {
			cout << -1 << endl;
		}
	}
	//system("pause");
	return 0;
}