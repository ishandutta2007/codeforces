#include <iostream>
using namespace std;
int uf[100100];
int c,n;
int f(int x) { if (uf[x] == x)return x; return uf[x] = f(uf[x]); }
void u(int x, int y) { if (f(x) != f(y))c--; uf[f(x)] = uf[f(y)]; }
int main()
{
	cin >> n;
	c = n;
	int i;
	for (i = 1; i <= n; i++)
	{
		uf[i] = i;
	}
	for (i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		u(i + 1, a);
	}
	cout << c;
}