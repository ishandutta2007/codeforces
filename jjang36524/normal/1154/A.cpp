#include <iostream>
using namespace std;
#include <algorithm>
int main()
{
	int a[4];
	cin >> a[0] >> a[1] >> a[2] >> a[3];
	sort(a, a + 4);
	cout << a[3] - a[2] << ' ' << a[3] - a[1] << ' ' << a[3] - a[0];
}