#include <bits/stdc++.h>
using namespace std;
const int N = 100100;
int a[2][N];
int n, q;
int cnt;
 
void change(int x, int y) {
	for (int z = y - 1; z <= y + 1; z++) {
		if (z < 0 || z >= n) continue;
		cnt -= a[x][y] & a[x ^ 1][z];
	}
	a[x][y] ^= 1;
	for (int z = y - 1; z <= y + 1; z++) {
		if (z < 0 || z >= n) continue;
		cnt += a[x][y] & a[x ^ 1][z];
	}
}
 
int main(){
	cin >> n >> q;
	while(q--) {
		int x, y;
		cin >> x >> y;
		x--;y--;
		change(x, y);
		if (cnt == 0) cout << "Yes\n";
		else cout << "No\n";
	}
 
	return 0;
}