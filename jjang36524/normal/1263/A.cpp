#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <string>
#include <map>
using namespace std;
int N, M;
vector<int>h;
int uf[200100];
int coun;
int f(int x)
{
	if (uf[x] == x)
		return x;
	return uf[x] = f(uf[x]);
}
void u(int a, int b)
{
	if (f(a) == f(b))
		return;
	coun--;
	uf[f(a)] = uf[f(b)];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		vector<int>d = { a,b,c };
		sort(d.begin(), d.end());
		if (d[2] > d[1] + d[0])
			cout << d[1] + d[0] << '\n';
		else
			cout << (d[2] + d[1] + d[0]) / 2 << '\n';
	}
}