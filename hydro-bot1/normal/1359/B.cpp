// Hydro submission #62321ca01863d68279ddca81@1647451296995
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
	int t, n, m, x, y;
	int cnt1, cnt2;
	string flg;
	scanf("%d", &t);
	while (t--)
	{
		cnt1 = 0; cnt2 = 0;
		scanf("%d%d%d%d", &n, &m, &x, &y);
		for (int i = 0; i < n; i++)
		{
			cin >> flg;
			for (int j = 0; j < m; j++)
			{
				if (flg[j] == '.')cnt1++;
			}
			for (int j = 0; j < m; j++)
			{
				if (flg[j] == '.' && flg[j + 1] == '.')
				{
					cnt2++; j++;
				}
			}
		}
		if (2 * x > y)
		{
			printf("%d\n", cnt2 * y + (cnt1 - 2 * cnt2) * x);
		}
		else
			printf("%d\n", cnt1 * x);
	}
	return 0;
}