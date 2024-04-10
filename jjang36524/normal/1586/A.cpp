#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int isp(int n)
{
	int i;
	for (i = 2; i < n; i++)
	{
		if (n % i == 0)
			return 1;
	}
	return 0;
}
int main()
{
	int T;
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		vector<int>x;
		int i;
		int su = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			su+=a;
			x.push_back(a);
		}
		if (isp(su))
		{
			cout << N << '\n';
			for (i = 0; i < N; i++)
			{
				cout << i+1 << ' ';
			}
		}
		else
		{
			
			for (i = 0; i < N; i++)
			{
				if (isp(su - x[i]))
				{
					cout << N - 1 << '\n';
					int j;
					for (j = 0; j < N; j++)
					{
						if (j != i)
						{
							cout << j+1 << ' ';
						}
					}
					goto T;
				}
			}
			for (i = 0; i < N; i++)
			{
				int k;
				for (k = i + 1; k < N; k++)
				{
					if (isp(su - x[i]))
					{
						cout << N - 2 << '\n';
						int j;
						for (j = 0; j < N; j++)
						{
							if (j != i&&j!=k)
							{
								cout << j + 1 << ' ';
							}
						}
						goto T;
					}
					
				}
				
			}
			for (i = 0; i < N; i++)
			{
				int k;
				for (k = i + 1; k < N; k++)
				{
					int l;
					for (l = k + 1; l < N; l++)
					{
						if (isp(su - x[i]))
						{
							cout << N - 3 << '\n';
							int j;
							for (j = 0; j < N; j++)
							{
								if (j != i&&j!=k&&j!=l)
								{
									cout << j + 1 << ' ';
								}
							}
							goto T;
						}
						
					}
					
				}

			}
			
		}
		T:
		cout << '\n';
	}
}