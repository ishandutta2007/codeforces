#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <deque>
#include <cassert>

using namespace std;

#define PI 3.14159265
typedef long long ll;

const ll INF = 4 * 1e18;
const int INFi = 2 * 1e9;
ll mod = 1e9 + 7;


int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int x, y, z, a, b, c;
	cin >> x >> y >> z >> a >> b >> c;
	a -= x;
	if (a < 0) cout << "NO\n";
	else {
		int d = a + b;
		d -= y;
		if (d < 0) cout << "NO\n";
		else {
			int f = d + c;
			f -= z;
			if (f < 0) cout << "NO\n";
			else cout << "YES\n";
		}
	}
	//system("pause");
	return 0;
}