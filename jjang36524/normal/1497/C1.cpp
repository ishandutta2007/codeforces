#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
#include <set>
using namespace std;
int don[101];
int cou[100100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N,M;
		cin >> N>>M;
		int mul = 1;
		int suc = 1;
		while (N % 2 == 0)
		{
			if (N == 4)
			{
				cout << mul << ' ' << mul << ' ' << 2 * mul << '\n';
				suc = 0;
				break;
			}
			N /= 2;
			mul *= 2;
		}
		if(suc)
			cout << (N / 2) * mul << ' ' << (N / 2) * mul << ' ' << mul << '\n';
	}
}