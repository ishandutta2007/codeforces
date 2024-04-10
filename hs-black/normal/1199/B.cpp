#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<iomanip>
using namespace std;
#define ll long double
int main() {
	ll X;
	long long h, l, x;
	cin >> h >> l;
	x = h * h + l * l;
	X = (ll)x / 2.0;
	X /= (ll)h;
	cout << fixed << setprecision(13) << X - (ll)h << endl;
	return 0;
}