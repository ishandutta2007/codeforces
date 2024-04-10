	#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <random>

using namespace std;

typedef long long ll;

ll INF = 1e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;
int p = 47;

vector<int> z_function(vector<int> a) {
	int n = a.size();
	vector<int> z(n);
	for (int i = 1, l = 0, r = 0; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n && a[z[i]] + (a[i] - a[0]) == a[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) {
			l = i;
			r = i + z[i] - 1;
		}
		//cout << i << " " << z[i] << " " << l << " " << r << " " << a[i] - a[0] << endl;
	}
	return z;
}

int main(){
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
	
	int n, w;
	cin >> n >> w;
	vector<int> a(n + w + 1);
	for (int i = 0; i < n; i++) {
		cin >> a[w + 1 + i];
	}
	a[w] = INFi;
	for (int i = 0; i < w; i++) {
		cin >> a[i];
	}
	vector<int> z = z_function(a);
	int cnt = 0;
	for (int i = w + 1; i < z.size(); i++) {
		//cout << z[i] << endl;
		if (z[i] == w)
			cnt++;
	}
	cout << cnt << endl;
	//system("pause");
	return 0;
}