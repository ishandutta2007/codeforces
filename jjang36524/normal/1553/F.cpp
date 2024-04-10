#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
#define int long long
#define DIV 725
signed ft[5000100];
#pragma GCC target ("avx,avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
inline void upd(int n, int k)
{
	while (n <= 300000)
	{
		ft[n] += k;
		n += n & -n;
		ft[n] += k;
		n += n & -n;
		ft[n] += k;
		n += n & -n;
	}
}
inline int get(int n)
{
	int ans = 0;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	ans += ft[n];
	n -= n & -n;
	return ans;
}
int ft2[5000100];
inline void upd2(int n, int k)
{
	while (n <= 300000)
	{
		ft2[n] += k;
		n += n & -n;
		ft2[n] += k;
		n += n & -n;
		ft2[n] += k;
		n += n & -n;
	}
}
inline int get2(int n)
{
	int ans = 0;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	ans += ft2[n];
	n -= n & -n;
	return ans;
}
int cousmalls[DIV+1];
int countmod[DIV + 1][DIV+1];
int modcal[DIV + 1][DIV + 1];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i,j;
	for (i = 0; i <= DIV; i++)
	{
		for (j = 1; j <= DIV; j++)
		{
			modcal[i][j] = (i % j);
		}
	}
	int su = 0;
	int bigcou = 0;
	int smallsu = 0;
	int bigsu = 0;
	for (i = 1; i <= N; i++)
	{
		int a;
		cin >> a;
		if (a < DIV)
		{
			int j;
			for (j = 1; j ^ DIV; j++)
			{
				su += cousmalls[j] * (modcal[a][j]+modcal[j][a]);
			}
			for (j = 0; j ^ a; j++)
			{
				su += countmod[a][j] * j;
			}
			su += bigcou*a;
			cousmalls[j]++;
			smallsu += a;
		}
		else
		{
			su += smallsu;
			int j;
			for (j = 1; j ^ DIV; j++)
			{
				su += cousmalls[j] * (a%j);
			}
			su += bigsu;
			su += a * bigcou;
			su += get2(a);
			int c = 0;
			int re = get(300000);
			for (j = a; j <= 300000; j += a)
			{
				c++;
				upd2(j, -a);
				su -= (re - get(j - 1))*a;
			}
			for (j = 1; j ^DIV; j++)
			{
				countmod[j][a % j]++;
			}
			upd(a, 1);
			bigsu+=a;
			bigcou++;
		}
		cout << su << ' ';
	}
}