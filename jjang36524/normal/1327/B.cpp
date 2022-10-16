#include <iostream>
#include <algorithm>
#include <vector>
#define int long long
using namespace std;
int T;
int occ[100100];
int suc[100100];
signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		for (i = 0; i < N; i++)
		{
			int k, j;
			cin >> k;
			for (j = 0; j < k; j++)
			{
				int a;
				cin >> a;
				if (!occ[a]&&!suc[i])
				{
					suc[i] = 1;
					occ[a] = 1;
				}
			}
		}
		int f = N, s =N;
		for (i = 0; i < N; i++)
		{
			if (f == N && !suc[i])
				f = i;
			if (s == N && !occ[i+1])
				s = i;
		}
		if (f == N)
			cout << "OPTIMAL" << '\n';
		else
			cout<<"IMPROVE"<<'\n' << f + 1 <<' '<<s + 1<<'\n';
		for (i = 1; i <= N; i++)
			occ[i] =suc[i-1]= 0;
	}
}