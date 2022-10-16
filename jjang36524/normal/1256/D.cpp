#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
long long N,M,D;
string s;
int zeropos[1000100];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> N;
	while (N--)
	{
		cin >> M>>D;
		cin >> s;
		int i;
		int count1=0;
		for (i = 0; i < M; i++)
		{
			if (s[i] == '0')
				zeropos[i - count1] = count1;
			else
				count1++;
		}
		int total = M - count1;
		for (i = 0; i < total; i++)
		{
			int old = zeropos[i];
			zeropos[i] -= min(D, (long long)zeropos[i]);
			D -=old;
			if (zeropos[i])
				break;
		}
		int now0 = 0;
		count1 = 0;
		for (i = 0; i < M; i++)
		{
			if (now0!=total&&zeropos[now0] == count1)
			{
				cout << 0;
				now0++;
			}
			else
			{
				cout << 1;
				count1++;
			}
		}
		cout << '\n';
	}
}