#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define fs first
#define sc second
#define endl "\n"
using namespace std;

main() {
	ios_base::sync_with_stdio(0);
	int n;
	cin >> n;
	int a[n][n];
	int x;
	int y;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
			if (a[i][j] == 0){
				x = i;
				y = j;
			}
		}
	}
	if (n == 1){
		cout << 1;
		return 0;
	}
	int x1 = (x + 1) % n;
	int summ = 0;
	for (int i = 0; i < n; i++){
		summ += a[x1][i];
	}
	int summ1 = 0;
	for (int i = 0; i < n; i++){
		summ1 += a[x][i];
	}
	int prav = 1;
	a[x][y] = summ - summ1;
	for (int i = 0; i < n; i++){
		int res = 0;
		for (int j = 0; j < n; j++){
			res += a[i][j];
		}
		if (res != summ){
			prav = 0;
		}
	}
	for (int i = 0; i < n; i++){
		int res = 0;
		for (int j = 0; j < n; j++){
			res += a[j][i];
		}
		if (res != summ){
			prav = 0;
		}
	}
	int res = 0;
	for (int i = 0; i < n; i++){
		res += a[i][i];
	}
	if (res != summ){
		prav = 0;
	}
	res = 0;
	for (int i = 0; i < n; i++){
		res += a[i][n - i - 1];
	}
	if (res != summ){
		prav = 0;
	}
	if (prav && a[x][y] > 0){
		cout << a[x][y];
	}
	else{
		cout << -1;
	}
}