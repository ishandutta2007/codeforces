#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <fstream>
#include <stdio.h>
#include <iomanip>
#include <clocale>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
using namespace std;
  
#define int long long
#define endl '\n'
typedef long double ld;

#define M_PI acos(-1)

int32_t main() {
	ios_base::sync_with_stdio(0);
    cin.tie(0);

	vector<ld> ag;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		ld tmp = atan2(y, x);
		ag.push_back(tmp);
	}	
	auto cmp = [&](int i, int j) {
		return ag[i] < ag[j];
	};
	vector<int> ind(n);
	for (int i = 0; i < n; i++) {
		ind[i] = i;
	}
	sort(ind.begin(), ind.end(), cmp);
	ld best = 1e9;
	int f = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		int nx = (i + 1) % n;
		ld cur = abs(ag[ind[nx]] - ag[ind[i]]);
		cur = min(cur, 2 * M_PI - cur);
		//cout << cur << endl;
		if (cur < best) {
			best = cur;
			f = ind[nx];
			s = ind[i];
			//cout << ind[i] << ' ' << ind[nx] << endl;
		}
	}
	//cout << best << endl;
	cout << f + 1 << ' ' << s + 1 << endl; 

}