#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
const ll mod = 998244353;

int main() {
	ios::sync_with_stdio(0);
	cout.tie(0);
	cin.tie(0);
	char mat[9][9];
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			cin >> mat[i][j];
	int x, y;
	cin >> x >> y, x--, y--;
	char c = mat[x][y];
	x %= 3;
	y %= 3;
	int can = 0;
	for (int i = x * 3; i < (x * 3) + 3; i++)
		for (int j = y * 3; j < (y * 3) + 3; j++)
			can |= mat[i][j] == '.';
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++) {
			if (mat[i][j] == '.') {
				if (i / 3 == x && j / 3 == y)
					mat[i][j] = '!';
				if(can==0)
					mat[i][j] = '!';
			}
			cout << mat[i][j];
			if(j%3 == 2)
				cout << " \n"[j==8];
			if(j==8&&i%3 == 2)
				cout << "\n";
		}

}