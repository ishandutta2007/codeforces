#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m, d;
int x1[100005], y1[100005], x2[100005], y2[100005];
int cl, cr, ct, cb;

int mxl[100005], mxr[100005], myl[100005], myr[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> d >> n >> m;
	for (int i=1; i<=d; i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		if (x1[i] > x2[i]) {
			swap(x1[i], x2[i]);
		}
		if (y1[i] > y2[i]) {
			swap(y1[i], y2[i]);
		}
	}
	cin >> cl >> cr >> ct >> cb;

	for (int i=1; i<=d; i++) {
		mxl[x1[i]]++;
		mxr[x2[i]]++;
		myl[y1[i]]++;
		myr[y2[i]]++;
	}

	for (int i=1; i<=100001; i++) {
		mxl[i] += mxl[i-1];
		myl[i] += myl[i-1];
	}

	for (int i=100000; i>=0; i--) {
		mxr[i] += mxr[i+1];
		myr[i] += myr[i+1];
	}	

	for (int i=1; i<=d; i++) {
		int zxl = mxl[x2[i]-1];
		int zxr = mxr[x1[i]+1];
		int zyl = myl[y2[i]-1];
		int zyr = myr[y1[i]+1];

		if (x2[i] != x1[i]) {
			zxl--;
			zxr--;
		}

		if (y2[i] != y1[i]) {
			zyl--;
			zyr--;
		}

		if (zxl == cl && zxr == cr
			&& zyl == ct && zyr == cb)
		{
			cout << i;
			return 0;
		} else {
			// cerr << zxl << ' ' << zxr << ' ' << zyl << ' ' << zyr << '\n';

		}
	}
	cout << -1;
}