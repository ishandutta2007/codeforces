#include <iostream>
using namespace std;

bool u[1001];
bool u1[1001];

int main() {
	int n, k, a, b, c, d;
	cin >> n >> k >> a >> b >> c >> d;
	if (n == 4 || k <= n){
		cout << -1;
		return 0;
	}
	
	u[a] = true;
	u[b] = true;
	u[c] = true;
	u[d] = true;
	u1[a] = true;
	u1[b] = true;
	u1[c] = true;
	u1[d] = true;
	cout << a << ' ' << d << ' ';
	for (int i = 1; i <= n; i++){
		if (!u[i]){
			cout << i << ' ';
			u[i] = 1;
		}
	}
	cout << c << ' ' << b << endl;
	cout << c << ' ' << b << ' ';
	for (int i = 1; i <= n; i++){
		if (!u1[i]){
			cout << i << ' ';
			u1[i] = 1;
		}
	}
	cout << a << ' ' << d << endl;
}