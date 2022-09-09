#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <cmath>
#include <string>
#include <algorithm>
#include <cstring>
#include <ctime>
#include <stack>
#include <list>
#include <cassert>
using namespace std;
typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int, int> pi;

#define mp make_pair
#define pb push_back
#define all(s) s.begin(), s.end()
void solve();

int main() {
#ifdef room210
	freopen("in.txt", "r", stdin);
	clock_t start = clock();
#else
	//freopen("circles.in", "r", stdin);
	//freopen("circles.out", "w", stdout);
#endif
	//ios_base::sync_with_stdio(false);
	int t = 1;
	//cin >> t;
	while (t--)
		solve();

#ifdef room210
	cout << "\n\n\n\nTime:" << ((clock() - start) / 1.0 / CLOCKS_PER_SEC);
#endif
	return 0;
}

#define int li

double eps = 1e-9;

int y[2];
int Y;
int r;
pair <int, int> start;

void solve() {
	cin>>y[0]>>y[1]>>Y>>start.first>>start.second>>r;
	if (y[0] > y[1])
		swap(y[0], y[1]);
	if (y[1] - y[0] <= 2 * r){
		cout<<"-1";
		return;
	}
	Y -= r;
	y[0] = 2 * Y - y[0];
	y[1] = 2 * Y - y[1];
	//cout<<y[0]<<' '<<y[1]<<endl;
	if (1.0 * r * sqrt( 1.0 * start.first * start.first + 1.0 * (y[0] - r - start.second) * (y[0] - r - start.second) ) + eps > 1.0 * start.first * (y[0] - y[1] - r)){
		cout<<"-1";
		return;
	}
	double ans = 1.0 * (y[0] - r - Y) * start.first;
	ans /= 1.0 * (y[0] - r - start.second);
	printf("%.15lf\n", ans);
}