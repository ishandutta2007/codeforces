#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <vector>
#define int long long
using namespace std;
int inp[100100];
vector<int>arr;
int psum[100100][30];
int ans = 1LL << 50;
void sear(vector<int>sub,int di)
{
	if (sub.size() <= 1 || di == -1)
		return;
	int i;
	vector<int>z, o;
	for (i = 0; i < sub.size(); i++)
	{
		if (inp[sub[i]] & (1 << di))
		{
			o.push_back(sub[i]);
		}
		else
		{
			z.push_back(sub[i]);
		}
	}
	int s = 0, e = 0;
	while (e != o.size()&&s!=z.size())
	{
		if (o[e] <= z[s] || psum[o[e] - 1][di] - psum[z[s]][di] == 0)
		{
			e++;
		}
		else
		{
			ans = min(o[e] - z[s] - 1, ans);
			s++;
		}
	}
	s = 0, e = 0;
	while (e != z.size()&&s!=o.size())
	{
		if (z[e] <= o[s] || psum[z[e] - 1][di] - psum[o[s]][di] == z[e]-o[s]-1)
		{
			e++;
		}
		else
		{
			ans = min(z[e] - o[s] - 1, ans);
			s++;
		}
	}
	sear(o, di - 1);
	sear(z, di - 1);
}
signed main()
{
	int N;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	arr.push_back(0);
	int i;
	int v = 0;
	for (i = 1; i <= N; i++)
	{
		arr.push_back(i);
		int a;
		cin >> a;
		a ^= inp[i - 1];
		inp[i] = a;
		v = inp[i];
		int j;
		for (j = 0; j < 30; j++)
		{
			int p = 0;
			if ((1 << j) & v)
				p = 1;
			psum[i][j] = psum[i - 1][j] + p;
		}
	}
	sear(arr, 29);
	if (ans > 5*N)
		cout << -1;
	else
		cout << ans-1;
}