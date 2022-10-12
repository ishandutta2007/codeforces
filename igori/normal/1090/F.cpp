#include<iostream>
#include<algorithm>
using namespace std;
long long n;
long long c[500000];
long long get(int x, int y, int z)
{
	int a[3] = {x, y, z};
	sort(a, a + 3);
	//return a[0] + a[2];
	cout << "? " << x << " " << y << " " << z << endl;
	long long t;
	cin >> t;
	return t;
}
long long get(int x, int y, int z, int t)
{
	long long a[4] = {get(x, y, z), get(x, y, t), get(x, z, t), get(y, z, t)};
	sort(a, a + 4);
	return a[0] + a[3];
}
int main()
{
	cin >> n;
	long long A = get(1, 2, 3, 4);
	long long B = get(1, 2, 3, 5);
	long long C = get(1, 2, 4, 5);
	long long D = get(1, 3, 4, 5);
	long long E = get(2, 3, 4, 5);
	long long F = (A + B + C + D + E) / 4;
	c[1] = F - E;
	c[2] = F - D;
	c[3] = F - C;
	c[4] = F - B;
	c[5] = F - A;
	for (int i = 6; i <= n; i++)
	{
		long long u = get(1, 2, 3, i);
		c[i] = u - c[1] - c[2] - c[3];
	}
	cout << "! ";
	for (int i = 1; i <= n; i++)
	cout << c[i] << " ";
	cout << endl;
}