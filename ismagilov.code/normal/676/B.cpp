#include <bits/stdc++.h>
#define int long long
using namespace std;

double a[10][1024];

main() {
	int n, t;
	cin >> n >> t;
	for (int ii = 0; ii < t; ii++){
		int tek = 1;
		a[0][0]++;
		for (int i = 0; i < n; i++){
			for (int j = 0; j < 1024; j++){
				if (a[i][j] > 1){
					a[i+1][j] += (a[i][j] - 1) / 2;
					a[i+1][j+1] += (a[i][j] - 1) / 2;
					a[i][j] = 1;
				}
			}
			tek++;
		}
		//cout << ii << endl;
	}
	int kol = 0;
	int tek = 1;
	for (int i = 0; i < n; i++){
		for (int j = 0; j < tek; j++){
			if (a[i][j] >= 1){
				kol++;
			}
			//cout << a[i][j] << ' ';
		}
		tek++;
		//cout << endl;
	}
	cout << kol;
}