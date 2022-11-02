#include <iostream>
#include <algorithm>
using namespace std;

long long a[200009];

int main()
{
	ios::sync_with_stdio(false);
	long long n, s;
	cin >> n >> s;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	int md = (n + 1) / 2;
	long long r = 0;
	if (a[md] < s) {
		while (md <= n && a[md] < s) {
			r += s - a[md]; md++;
		}
	}
	else if (a[md] > s){
		while (0 < md && s < a[md]) {
			r += a[md] - s; md--;
		}
	}
	cout << r << '\n';
	return 0;
}