#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int h[19][19];
double d[19][19];
vector<double> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	for (int i = 1; i <= 10; i++)
		for (int j = 1; j <= 10; j++)
			cin >> h[i][j];
	double s = 0;
	d[1][1] = 0; v.push_back(0);
	for (int i = 2; i <= 7; i++) {
		double p = (double)(i - 1) / 6;
		double r = (s / 6 + (double)1) / p;
		v.push_back(r); d[1][i] = r; s += r;
	}
	for (int i = 1; i <= 10; i++) 
		for (int k = 1; k <= 10; k++) {
			if (i == 1 && k <= 7) continue;
			int j = k;
			if (i % 2 == 0) j = 11 - k;
			s -= v[(int)v.size() - 7];
			double r = s / 6 + (double)1; d[i][j] = r;
			if (h[i][j] > 0) r = min(r, d[i - h[i][j]][j]);
			v.push_back(r); s += r;
		}
	cout.setf(ios::fixed);
	cout.precision(20);
	cout << d[10][1] << '\n';
	return 0;
}