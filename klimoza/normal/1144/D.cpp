#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
#include <cmath>
#include <map>
#include <set>
#include <deque>

using namespace std;

typedef long long ll;

ll INF = 4e18;
int INFi = 2e9;
double eps = 1e-8;
ll mod = 1e9 + 7;

bool cmp(int x, int y) {
	return x > y;
}

int main() {
	cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
		
	int n;
	cin >> n;
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		b[i] = a[i];
	}
	sort(b.begin(), b.end());
	int cur = 1;
	int maxi = 0;
	int ff = -1;
	for (int i = 1; i < n; i++) {
		if (b[i] == b[i - 1]) cur++;
		else {
			if (maxi < cur) {
				maxi = cur;
				ff = b[i - 1];
			}
			cur = 1;
		}
	}
	if (maxi < cur) {
		maxi = cur;
		ff = b[n - 1];
	}
	cout << n - maxi << endl;
	int ind = -1;
	for (int i = 0; i < n; i++) {
		if (a[i] == ff) {
			ind = i;
			break;
		}
	}
	//cout << ind << endl;
	for (int i = ind - 1; i >= 0; i--) {
		if (a[i] > ff) cout << 2 << " ";
		else cout << 1 << " ";
		cout << i + 1 << " " << i + 2 << endl;
	}
	for (int i = ind + 1; i < n; i++) {
		if (a[i] == ff) continue;
		if (a[i] > ff) cout << 2 << " ";
		else cout << 1 << " ";
		cout << i  + 1 << " " << i << endl;
	}
	//system("pause");
	return 0;
}