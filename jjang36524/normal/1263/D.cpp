#include <algorithm>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
#include <string>
using namespace std;
int N, M;
vector<int>h;
int uf[200100];
int coun;
int f(int x)
{
	if (uf[x] == x)
		return x;
	return uf[x] = f(uf[x]);
}
void u(int a, int b)
{
	if (f(a) == f(b))
		return;
	coun--;
	uf[f(a)] = uf[f(b)];
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	coun = N;
	int i,j;
	for (i = 0; i < N; i++)
	{
		int a = 0;
		string s;
		cin >> s;
		int si = s.size();
		for (j = 0; j < si; j++)
		{
			a |= (1 << (s[j] - 'a'));
		}
		h.push_back(a);
		uf[i] = i;
	}
	sort(h.begin(), h.end());
	for (i = 0; i < 26; i++)
	{
		int firstno = -1;
		for (j = 0; j < N; j++)
		{
			if (h[j] & (1 << i))
			{
				if (firstno == -1)
					firstno = j;
				else
					u(j, firstno);
			}
		}
	}
	cout << coun;
}