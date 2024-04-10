#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
using namespace std;
int ps[200100];
int N;
int nowmoney[200100];
vector<int>noplist;
vector<int>payout;
int maxcals[200100];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		cin >> nowmoney[i];
	}
	int M;
	cin >> M;
	for (i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a;
		if (a == 1)
		{
			cin >> b >> c;
			noplist.push_back(b-1);
			nowmoney[b-1] = c;
			ps[b-1] = -1;
		}
		else
		{
			cin >> b;
			int j;
			for (j = 0; j < noplist.size(); j++)
			{
				ps[noplist[j]] = payout.size();
			}
			payout.push_back(b);
			noplist.clear();
		}
	}
	for (i = payout.size() - 1; i >= 0; i--)
	{
		maxcals[i] = max(maxcals[i + 1], payout[i]);
	}
	for (i = 0; i < N; i++)
	{
		if (ps[i] >= 0)
			cout <<max(nowmoney[i], maxcals[ps[i]]) << ' ';
		else
			cout << nowmoney[i] << ' ';
	}
}