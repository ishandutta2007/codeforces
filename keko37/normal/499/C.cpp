#include<iostream>

using namespace std;

int x1, y1;
int x2, y2;
int n;

int sol;

bool dif (int x1, int y1, int x2, int y2, double a, double b) {
	return (y1>a*x1+b && y2<a*x2+b) || (y1<a*x1+b && y2>a*x2+b);
}

int main () {
	cin >> x1 >> y1 >> x2 >> y2 >> n;
	for (int i=0; i<n; i++) {
		int aa, bb, cc;
		double a, b;
		cin >> aa >> bb >> cc;
		if (bb==0 && ((x1>((double) -cc/aa) && x2<((double) -cc/aa)) || (x1<((double) -cc/aa) && x2>((double) -cc/aa)))) {
			sol++;
			continue;
		}
		a=(double)-aa/bb;
		b=(double)-cc/bb;
		if (dif(x1, y1, x2, y2, a, b)) sol++;
	}
	cout << sol;
	return 0;
}