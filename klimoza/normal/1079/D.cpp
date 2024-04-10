#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <deque>
#include <cmath>
#include <deque>
#include <algorithm>

using namespace std;

typedef long long int ll;
typedef pair<long double, long double> pll;


long double lenf(pll po1, pll po2) {
	return sqrt((po1.first - po2.first) * (po1.first - po2.first) + (po1.second - po2.second) * (po1.second - po2.second));
}


int main() {
	cout.precision(15);
	long double a, b, c;
	cin >> a >> b >> c;
	long double x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	int delx = -2;
	int dely = -2;
	if (x2 > x1) delx = 1;
	else if (x2 == x1) delx = 0;
	else delx = -1;
	if (y2 > y1) dely = 1;
	else if (y2 == y1) dely = 0;
	else dely = -1;
	long double ans = abs(x2 - x1) + abs(y2 - y1);
	pll an1x = { x1, -(a * x1 + c) / b };
	pll an1y = { -(b * y1 + c) / a, y1 };
	pll an2x = { x2, -(a * x2 + c) / b };
	pll an2y = { -(b * y2 + c) / a, y2 };
	/*cout << an1x.first << " " << an1x.second << "\n";
	cout << an1y.first << " " << an1y.second << "\n";
	cout << an2x.first << " " << an2x.second << "\n";
	cout << an2y.first << " " << an2y.second << "\n";*/
	long double f1 = min(ans, lenf(an1x, an2x) + abs(y1 - an1x.second) + abs(y2 - an2x.second));
	long double f2 = min(ans, lenf(an1x, an2y) + abs(y1 - an1x.second) + abs(x2 - an2y.first));
	long double f3 = min(ans, lenf(an1y, an2x) + abs(x1 - an1y.first) + abs(y2 - an2x.second));
	long double f4 = min(ans, lenf(an1y, an2y) + abs(x1 - an1y.first) + abs(x2 - an2y.first));
	ans = min(ans, f1);
	ans = min(ans, f2);
	ans = min(ans, f3);
	ans = min(ans, f4);
	//cout << lenf(an1x, an2x) << " " << lenf(an1x, an2y) << " " << lenf(an1y, an2x) << " " << lenf(an1y, an2y) << "\n";
	//cout << f1 << " " << f2 << " " << f3 << " " << f4 << "\n";
	cout << ans << "\n";
	//system("pause");  
	return 0;
}