#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 1e18;
ll mod = 1e9 + 7;

int main() {
	int y, b, r;
	cin >> y >> b >> r;
	int a1 = 1;
	int a2 = 2;
	int a3 = 3;
	while (a1 < y && a2 < b && a3 < r) {
		a1++;
		a2++;
		a3++;
	}
	cout << a1 + a2 + a3 << endl;
	//system("pause");
	return 0;
}