#include <bits/stdc++.h>
using namespace std;
#define DB(x) cout << #x << " == " << x << "\n";
#define pb push_back
#define mp make_pair
#define vi vector<int>
#define pi pair<int, int>
#define LL long long
#define MAX 100010
//2r^2-r^2 * cos(a)
double n, r, cs, r2, lo, hi, mid, t;

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(0);
	cin >> n >> r;
	cs = 1 - cos(2 * 3.14159265359 / n);
	lo = 0;
	hi = 10 * r;
	while (hi - lo > 10e-8) {
		mid = (lo + hi) / 2.0;
		r2 = r + mid;
		t = sqrt(2 * r2 * r2 * cs)/2.0;
		if(abs(t - mid) < 10e-8) {
			printf("%.10lf", mid);
			return 0;
		}
		if(t > mid)
			lo = mid;
		else
			hi = mid;

	}
	printf("%.10lf", mid);
}