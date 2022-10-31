#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
#define x first
#define y second
using namespace std;
typedef pair <int, int> pii;

const int N = 1e5 + 5;

pii a[N];

struct node {
	int x1, y1, x2, y2;
};
vector <node> ans;

int main () {
	for (int i = 1;i <= 3;++i) {
		cin >> a[i].x >> a[i].y;
	}
	sort(a + 1, a + 3 + 1);
	
	int miny = min({a[1].y, a[2].y, a[3].y});
	int maxy = max({a[1].y, a[2].y, a[3].y});
	if (miny < maxy) ans.pb({a[2].x, miny, a[2].x, maxy});
	if (a[1].x < a[2].x) ans.pb({a[1].x, a[1].y, a[2].x, a[1].y});
	if (a[2].x < a[3].x) ans.pb({a[3].x, a[3].y, a[2].x, a[3].y});
	
	cout << ans.size() << endl;
	for (auto [x1, y1, x2, y2] : ans) {
		cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
	}
}