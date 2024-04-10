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

vector<pair<int, int>> ans;


void gen(int x1, int y1, int x2, int y2) {
	if (x1 > x2 || y1 > y2) {
		return;
	}
	if (x2 == x1) {
		int l = y1;
		int r = y2;
		while (r >= l) {
			ans.push_back(make_pair(x1, l));
			if (l == r) {
				break;
			}
			ans.push_back(make_pair(x1, r));
			l++;
			r--;
		}
		return;
	}
	int r = y2;
	for (int l = y1; l <= y2; l++) {
		ans.push_back(make_pair(x1, l));
		ans.push_back(make_pair(x2, r));
		r--;
	}
	gen(x1 + 1, y1, x2 - 1, y2);
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    gen(1, 1, n, m);
    for (int i = 0; i < ans.size(); i++) {
    	cout << ans[i].first << " " << ans[i].second << endl;
    }
}