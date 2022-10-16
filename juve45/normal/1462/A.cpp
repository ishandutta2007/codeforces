
//1462A
#include <bits/stdc++.h>
#define st first
#define nd second

using namespace std;

int t, n, a[333], b[333];

int main() {



	//a =  1 2 3 4 5 6 7
	//b =  1 3..       2
	//	     st        dr

	cin >> t;
	for(int j = 1; j <= t; j++) {
		cin >> n;
		for(int i = 1; i <= n; ++i) 
			cin >> b[i];

		int st = 1, dr = n;

		for(int i = 1; i <= n; i++) {
			// unde e a[i]
			if(i % 2 == 1) {
				a[i] = b[st];
				st++;
			} else {
				a[i] = b[dr];
				dr--;
			}
		}
		for(int i = 1; i <= n; i++)
			cout << a[i] << ' ';
		cout << '\n';
	}
}