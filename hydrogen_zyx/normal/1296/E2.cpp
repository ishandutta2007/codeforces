#include<iostream>
#include<queue>
#include<cmath>
#include<algorithm>
#include<set>
using namespace std;
set<int> a[26];
int c[300000];
int main() {
	ios::sync_with_stdio(false);
	int n, cnt = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		char ch;
		cin >> ch;
		int k = ch - 'a';
		if (k == 25) {
			c[i] = 1;
			for (int kk = 0; kk <= 25; kk++) {
				a[kk].insert(1);
			}
			continue;
		}
		int can = 0;
		int j = 1;
		while (a[k + 1].count(j)) j++;
		c[i] = j;
		cnt = max(cnt, j);
		for (int kk = 0; kk <= k; kk++) {
			a[kk].insert(j);
		}
	}
	cout << cnt << endl;
	for (int i = 0; i < n; i++) {
		cout << c[i] << ' ';
	}
}