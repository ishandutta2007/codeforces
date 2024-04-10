#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int n, k, a, b, c, d;

int main () {
  cin >> n >> k >> a >> b >> c >> d;
	if (n==4 || n+1>k) {
		cout << -1;
		return 0;
	}
	cout << a << " " << c << " ";
	for (int i=1; i<=n; i++) {
		if (i!=a && i!=b && i!=c && i!=d) cout << i << " ";
	}
	cout << d << " " << b << endl;
	cout << c << " " << a << " ";
	for (int i=1; i<=n; i++) {
		if (i!=a && i!=b && i!=c && i!=d) cout << i << " ";
	}
	cout << b << " " << d << endl;
	return 0;
}