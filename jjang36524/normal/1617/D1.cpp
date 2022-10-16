#include <iostream>
#include <algorithm>
#include <vector>
#include <string.h>
using namespace std;
int group[100100];
int cr[100100];
int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(cr, -1, sizeof(cr));
		int N;
		cin >> N;
		int i;
		int ig = -1;
		int cg = -1;
		for (i = 0; i < N; i += 3)
		{
			cout << "? " << i + 1 << ' ' << i + 2 << ' ' << i + 3 << '\n';
			cout.flush();
			cin >> group[i];
			if (group[i] == 0 && ig == -1)
				ig = i/3;
			if (group[i] == 1 && cg == -1)
				cg = i/3;
		}
		int cig[3] = { 0,0,0 };
		int ccg[3] = { 0,0,0 };
		int cp = -1;
		int ip = -1;
		for (i = 0; i < 3; i++)
		{
			int j;
			for (j = 0; j < 3; j++)
			{
				if (i == j)
					continue;
				cout << "? " << i + cg * 3 + 1;
				int k;
				for (k = 0; k < 3; k++)
				{
					if (k == j)
						continue;
					cout << ' ' << k + ig * 3 + 1;
				}
				cout << '\n';
				cout.flush();
				int x;
				cin >> x;
				cig[j]+=x;
			}
		}
		for (i = 0; i < 3; i++)
		{
			cr[i + ig * 3] = !((cig[(i + 1) % 3] == 0) || (cig[(i + 2) % 3] == 0));
			if (!cr[i + ig * 3])
			{
				if (ip == -1)
					ip = i + ig * 3;
			}
			else
			{
				if (cp == -1)
					cp = i + ig * 3;
			}
		}
		int j;
		for (j = 0; j < 3; j++)
		{
			i = (j + 1) % 3;
			if (cr[i+ig*3])
				i = (j + 2) % 3;
			{
				cout << "? " << i + ig * 3 + 1;
				int k;
				for (k = 0; k < 3; k++)
				{
					if (k == j)
						continue;
					cout << ' ' << k + cg * 3 + 1;
				}
				cout << '\n';
				cout.flush();
				int x;
				cin >> x;
				ccg[j] += x;
			}
		}
		
		for (i = 0; i < 3; i++)
		{
			cr[i + cg * 3] = ((ccg[(i + 1) % 3] == 1) || (ccg[(i + 2) % 3] == 1));
			if (!cr[i + cg * 3])
			{
				if (ip == -1)
					ip = i + cg * 3;
			}
			else
			{
				if (cp == -1)
					cp = i + cg * 3;
			}
		}
		for (i = 0; i < N; i++)
		{
			if (cr[i] == -1)
			{
				cout << "? " << i + 1 << ' ' << ip + 1 << ' ' << cp + 1 << '\n';
				cout.flush();
				int x;
				cin >> x;
				cr[i] = x;
			}
		}
		int cnt = 0;
		for (i = 0; i < N; i++)
		{
			cnt += 1-cr[i];
		}
		cout << "! " << cnt<<' ';
		for (i = 0; i < N; i++)
		{
			if (!cr[i])
				cout << i + 1 << ' ';
		}
		cout << '\n';
		cout.flush();

	}
}