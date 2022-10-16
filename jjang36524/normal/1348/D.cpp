#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#define int long long
using namespace std;
int T, N,K;
int arr[26];
string p[26];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		cin >> N;
		int i;
		int nowv = 1;
		int p=1;
		for (i = 0; p < N; i++)
		{
			p = p * 2 + 1;
		}
		cout << i << '\n';
		int nowc = i+1;
		int y = i;
		for (i = 0; i < y; i++)
		{
			int j;
			int l = 0, r = nowv;
			while(l!=r)
			{
				j = (l + r) / 2;
				int ay = (nowv+j)*((1<<(y-i))-y+i-1);
				if ((j) * (y - i) + ay >= N - nowc)
					r = j;
				else
					l = j + 1;
			}
			j = l;
			cout << j << ' ';
			nowc += j * (y - i);
			nowv += j;
		}
		cout << '\n';
	}
}