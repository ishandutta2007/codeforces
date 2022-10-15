#define _CRT_SECURE_NO_WARNINGS
#pragma comment(linker, "/STACK:64000000")
#define _USE_MATH_DEFINES
#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<algorithm>
#include<cmath>
#include<set>
#include<queue>
#include<sstream>
#include<utility>
#include<map>

using std::pair;
using std::stringstream;
using std::next_permutation;
using std::sqrt;
using std::priority_queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::min;
using std::max;
using std::set;
using std::swap;
using std::random_shuffle;
using std::queue;
using std::sin;
using std::cos;
using std::make_pair;
using std::cos;
using std::cerr;
using std::map;

typedef long long ll; 
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;
const long double PI = 3.14159265358979323846;  

int INF = 1000 * 300 * 4;
int d[600][300][300];
int n;

void update(int i, int k, int l) {
	d[i][k][l] = -INF;
	int up = min(i, 2 * n - i);
	if (i <= n - 1) {
	if (k < up)
		d[i][k][l] = max(d[i][k][l], d[i - 1][k][l]);
	if (k > l)
		d[i][k][l] = max(d[i][k][l], d[i - 1][k - 1][l]);
	if ((l > 0) && (k < up))
		d[i][k][l] = max(d[i][k][l], d[i - 1][k][l - 1]);
	if (l > 0)
		d[i][k][l] = max(d[i][k][l], d[i - 1][k - 1][l - 1]);
	}
	else {
		if (k < up)
			d[i][k][l] = max(d[i][k][l], d[i - 1][k][l]);
		if (k + 1 < up)
			d[i][k][l] = max(d[i][k][l], d[i - 1][k + 1][l]);
		if (k > l)
			d[i][k][l] = max(d[i][k][l], d[i - 1][k][l + 1]);
		if (k + 1 < up)
			d[i][k][l] = max(d[i][k][l], d[i - 1][k + 1][l + 1]);
	}
	return;
}

int main() {
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	cin >> n;
	vector<vector<int> > data(n, vector<int> (n));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> data[i][j];
	d[0][0][0] = data[0][0];
	if (n == 1) {
		cout << data[0][0] << endl;
		return 0;
	}
	//d[1][1][0] = data[0][1] + data[0][0] + data[1][0];
	//d[1][1][1] = data[0][0] + data[1][0];
	//d[1][0][0] = data[0][0] + data[0][1];

	for(int i = 1; i < 2 * n - 1; ++i) {
		int up = min(i + 1, 2 * n - i - 1);
		for (int k = 0; k < up; ++k)
			for (int l = 0; l <= k; ++l) {
				update(i, k, l);
				if (k > l) {
					if (i < n)
						d[i][k][l] += data[i - l][l] + data[i - k][k];
					else
						d[i][k][l] += data[n - 1 - l][i - n + 1 + l] + data[n - 1 - k][i - n + k + 1];
				}
				else {
					if (i < n)
						d[i][k][l] += data[i - l][l];
					else
						d[i][k][l] += data[n - 1 - l][i - n + 1 + l];
				}
			}
	}
	cout << d[2 * n - 2][0][0] << endl;
	return 0;
}