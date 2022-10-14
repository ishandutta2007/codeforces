#include<iostream>

using namespace std;

int n, m, a, b, d;
int up, down;

int main () {
	cin >> n >> m >> a >> b;
	d=m-n;
	down=12*b;
	up=12*a;
	d-=8*a;
	if (d<=0) {
		cout << 0;
		return 0;
	}
	d+=down;
	if (up<=down) {
		if (d>a) cout << -1; else cout << 1;
		return 0;
	}
	int cnt=1;
	while (1) {
		d-=up;
		if (d<=0) {
			cout << cnt;
			break;
		}
		d+=down;
		cnt++;
	}
	return 0;
}