#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int T, a, b, c, d;
int main()
{
	cin >> T;
	while (T--)
	{
		int N, K;
		cin >> N >> K;
		int s = 0;
		if ((N-K) % 2==0)
		{
			int av = N / K;
			if (av % 2 == 0)
				av--;
			if (av >=1)
			{
				cout << "YES" << '\n';
				int ex = N - av * K;
				ex /= 2;
				int i;
				for (i = 0; i < K; i++)
				{
					if (i < ex)
						cout << av + 2 << ' ';
					else
						cout << av << ' ';
				}
				s = 1;
			}
			
		}
		if(N%2==0&&!s)
		{
			int av = N / K;
			if (av % 2)
				av--;
			if (av > 0)
			{
				cout << "YES" << '\n';
				int ex = N - av * K;
				ex /= 2;
				int i;
				for (i = 0; i < K; i++)
				{
					if (i < ex)
						cout << av + 2 << ' ';
					else
						cout << av << ' ';
				}
				s = 1;
			}
			
		}
		if (s == 0)
			cout << "NO";
		cout << '\n';
	}
}