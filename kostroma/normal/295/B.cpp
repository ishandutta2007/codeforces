#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
//void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

#define int li

int n;
int a[510][510];
int x[510];
int matrix[510][510];
bool have[510];

void solve () {
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) {
			cin >> a[i][j];
			matrix[i][j] = a[i][j];
		}
	for (int i = 0; i < n; ++i)
		cin >> x[i], --x[i];
	int sum = 0;
	vector <int> ans;
	for (int w = n - 1; w >= 0; --w) {
		int k = x[w];
		for (int i = 0; i < n; ++i)
			if (have[i])
				sum += matrix[i][k] + matrix[k][i];
		for (int i = 0; i < n; ++i)
			if (have[i])
				for (int j = 0; j < n; ++j)
					if (have[j]) {
						if (matrix[k][i] + matrix[i][j] < matrix[k][j]) {
							sum -= matrix[k][j] - matrix[k][i] - matrix[i][j];
							matrix[k][j] = matrix[k][i] + matrix[i][j];
						}
					}
		for (int i = 0; i < n; ++i)
			if (have[i])
				for (int j = 0; j < n; ++j)
					if (have[j]) {
						if (matrix[j][i] + matrix[i][k] < matrix[j][k]) {
							sum -= matrix[j][k] - matrix[j][i] - matrix[i][k];
							matrix[j][k] = matrix[j][i] + matrix[i][k];
						}
					}

		for (int i = 0; i < n; ++i)
			if (have[i])
				for (int j = 0; j < n; ++j)
					if (have[j]) {
						if (matrix[i][k] + matrix[k][j] < matrix[i][j]) {
							sum -= -matrix[i][k] - matrix[k][j] + matrix[i][j];
							matrix[i][j] = matrix[i][k] + matrix[k][j];
						}
					}

		have[k] = true;

		ans.push_back(sum);

	}

	for (int i = n - 1; i >= 0; --i)
		cout << ans[i] << ' ';

}