#include <iostream>
#include <vector>
using namespace std;
int N;
int main()
{
	cin >> N;
	while (N--)
	{
		int n;
		cin >> n;
		vector<int>a;
		int i;
		int la = 0;
		for (i = 0; i < n; i++)
		{
			int x;
			cin >> x;
			a.push_back(x);
		}
		la = a[0];
		if (n < 6)
		{
			cout << 0 << ' ' << 0 << ' ' << 0 << '\n';
		}
		else
		{
			int first = 0;
			int second = 0;
			int sum = 0;
			int now = 0;
			for (i = 0; i < (n+2) / 2; i++)
			{
				if (la == a[i])
					now++;
				else
				{
					sum += now;
					if (first == 0)
						first = now;
					else if (second <= first)
						second += now;
					now = 1;
				}
				la = a[i];
			}
			int third = sum - second - first;
			if (first < second && first < third)
			{
				cout << first << ' ' << second << ' ' <<third << '\n';
			}
			else
				cout << 0 << ' '<< 0 << ' ' << 0 << '\n';
		}
	}
}