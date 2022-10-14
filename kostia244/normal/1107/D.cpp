#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define ll long long
using namespace std;

int n, val, k, l, r, mid;
string s;
int mat[5201][5201] = { { 0, }, };

int sm(int x1, int y1, int x2, int y2) {
	int ans = mat[x2][y2];
	if (x1)
		ans -= mat[x1 - 1][y2];
	if (y1)
		ans -= mat[x2][y1 - 1];
	if (x1 && y1)
		ans += mat[x1 - 1][y1 - 1];
	return ans;
}

bool can() {
	for (int i = 0; i < n; i += mid) {
		for (int j = 0; j < n; j += mid) {
			if (!(sm(i, j, i + mid - 1, j + mid - 1) == 0
					|| sm(i, j, i + mid - 1, j + mid - 1) == mid * mid))
//				cout << i << " " << j << "\n";
				return false;
		}
	}
	return true;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0, k = 0; j < s.size() && k < n; j++, k += 4) {
			val = (s[j] < 'A' ? int(s[j] - '0') : int((s[j] - 'A') + 10));
			mat[i][k] = ((val >> 3) & 1), mat[i][k + 1] = ((val >> 2) & 1), mat[i][k
					+ 2] = ((val >> 1) & 1), mat[i][k + 3] = val & 1;
		}
	}

	for (int i = 0; i < n; i++)
		for (int j = (i == 0); j < n; j++)
			if (j == 0)
				mat[i][j] = mat[i - 1][j] + mat[i][j];
			else if (i == 0)
				mat[i][j] = mat[i][j - 1] + mat[i][j];
			else
				mat[i][j] = mat[i - 1][j] + mat[i][j - 1] + mat[i][j]
						- mat[i - 1][j - 1];
	int mx = 0;
	for (int i = 1; i * i <= n; i++) {
		if (n % i == 0) {
			if (n / i == i) {
				mid = i;
				if(i > mx && can())
					mx = i;
			} else {
				mid = i;
				if(i > mx && can())
					mx = i;

				mid = (n/i);
				if((n/i) > mx && can())
					mx = (n/i);
			}
		}
	}
	cout << mx;
}