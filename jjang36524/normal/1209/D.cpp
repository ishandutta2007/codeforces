#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
using namespace std;
int T;
int uf[5000031];
int coun[5000031];
bool findvis[200100];
int find(int x)
{
	if (x == uf[x] || uf[x] == 0)return x;
	return uf[x] = find(uf[x]);
}
void unio(int x, int y)
{
	if (find(x) == find(y))return;
	coun[find(x)] += coun[find(y)];
	uf[find(y)] = uf[find(x)];
}
int N, K;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N >> K;
	int i;
	for (i = 1; i <=N; i++)
	{
		coun[i] = 1;
		uf[i] = i;
	}
	for (i = 0; i < K; i++)
	{
		int a, b;
		cin >> a >> b;
		unio(a, b);
	}
	int ans = 0;
	for (i = 1; i <= N; i++)
	{
		if (!findvis[find(i)])
		{
			ans += coun[find(i)]-1;
			findvis[find(i)] = true;
		}
	}
	cout << K-ans;
}