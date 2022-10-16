#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
vector<int>pos[3][2];
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
		int i, j;
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 2; j++)
				pos[i][j].clear();
		}
		string arr[3];
		for (i = 0; i < 3; i++)
		{
			cin >> arr[i];
			for (j = 0; j < 2 * N; j++)
			{
				pos[i][arr[i][j] - '0'].push_back(j);
			}
		}
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (i == j)
					continue;
				if (pos[i][0].size() >= N && pos[j][0].size() >= N)
				{
					vector<int>zc;
					vector<int>oc;
					int k;
					int co = 0;
					for (k = 0; k < 2 * N; k++)
					{
						if (arr[i][k] == '0')
						{
							zc.push_back(co);
							co = 0;
						}
						else
						{
							co++;
						}
					}
					zc.push_back(co);
					co = 0;
					for (k = 0; k < 2 * N; k++)
					{
						if (arr[j][k] == '0')
						{
							oc.push_back(co);
							co = 0;
						}
						else
						{
							co++;
						}
					}
					oc.push_back(co);
					co = 0;

					for (k =0; k < max(zc.size(), oc.size()); k++)
					{
						int ce = 0;
						if (k)
							cout << 0;
						int an = 0;
						if (k < zc.size())
							an = max(an, zc[k]);
						if (k < oc.size())
							an = max(an, oc[k]);
						while (an--)
							cout << 1;
					}
					goto T;
				}
				if (pos[i][1].size() >= N && pos[j][1].size() >= N)
				{
					vector<int>zc;
					vector<int>oc;
					int k;
					int co = 0;
					for (k = 0; k < 2 * N; k++)
					{
						if (arr[i][k] == '1')
						{
							zc.push_back(co);
							co = 0;
						}
						else
						{
							co++;
						}
					}
					zc.push_back(co);
					co = 0;
					for (k = 0; k < 2 * N; k++)
					{
						if (arr[j][k] == '1')
						{
							oc.push_back(co);
							co = 0;
						}
						else
						{
							co++;
						}
					}
					oc.push_back(co);
					co = 0;
					for (k = 0; k < max(zc.size(), oc.size()); k++)
					{
						int ce = 0;
						if (k)
							cout << 1;
						int an = 0;
						if (k < zc.size())
							an = max(an, zc[k]);
						if (k< oc.size())
							an = max(an, oc[k]);
						while (an--)
							cout << 0;
					}
					goto T;
				}
			}
		}
		
	T:
		cout << '\n';
		int d;
	}
}