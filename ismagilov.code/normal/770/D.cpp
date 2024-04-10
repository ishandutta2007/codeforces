#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <bitset>

using namespace std;

char  p[150];

char ans[300][300];

int main() {	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cerr.tie(0);
	for (int i = 0 ; i < 300 ; i++) {
		for (int j = 0; j < 300; j++) {
			ans[i][j] = ' ';
		}
	}
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		 cin >> p[i];
	}
	int maxi = 0;
	for (int i = 0; i < n; i++) {
		int q = 0;
		for (int j = i; j < n; j++) {
			if (p[j] == ']') {
				q++;
			}
			else {
				q--;
			}
			maxi = max(maxi, abs(q));
		}
	}
	maxi = maxi * 2 + 1;
	int mid = maxi / 2;
	int raz = maxi / 2;
	vector <int> op;
	int pos = 1;
	ans[0][0] = '+';
	ans[1][0] = '-';
	for (int i = 1; i < maxi - 1; i++) {
		ans[0][i] = '|';
	}
	ans[0][maxi - 1] = '+';
	ans[1][maxi - 1] = '-';

	for (int i = 1; i < n; i++) {
		if (p[i] == ']') {
			if (p[i - 1] == ']') {
				raz++;
				ans[pos - 1][mid - raz] = '-';
				ans[pos][mid - raz] = '+';
				ans[pos - 1][mid + raz] = '-';
				ans[pos][mid + raz] = '+';
				for (int j = mid - raz + 1; j < mid + raz; j++) {
					ans[pos][j] = '|';
				}
			}
			else {
				pos += 3;
				ans[pos - 1][mid - raz] = '-';
				ans[pos][mid - raz] = '+';
				ans[pos - 1][mid + raz] = '-';
				ans[pos][mid + raz] = '+';
				for (int j = mid - raz + 1; j < mid + raz; j++) {
					ans[pos][j] = '|';
				}
			}
		}
		else {
			if (p[i - 1] == ']') {
				ans[pos + 1][mid - raz] = '-';
				ans[pos][mid - raz] = '+';
				ans[pos + 1][mid + raz] = '-';
				ans[pos][mid + raz] = '+';
				for (int j = mid - raz + 1; j < mid + raz; j++) {
					ans[pos][j] = '|';
				}
			}
			else {
				raz--;
				ans[pos + 1][mid - raz] = '-';
				ans[pos][mid - raz] = '+';
				ans[pos + 1][mid + raz] = '-';
				ans[pos][mid + raz] = '+';
				for (int j = mid - raz + 1; j < mid + raz; j++) {
					ans[pos][j] = '|';
				}
			}
		}
		pos++;
	}
	for (int i = 0; i < maxi; i++) {
		for (int j = 0; j < pos; j++) {
			cout << ans[j][i];
		}
		cout << endl;
	}
}