#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int T;
	cin >> T;
	while (T--)
	{
		int N;
		cin >> N;
		int i;
		int h = 1;
		int bef = 0;
		for (i = 0; i < N; i++)
		{
			int a;
			cin >> a;
			if (a == 0)
			{
				if (bef == 0&&i)
					h = -1;
			}
			else
			{
				if (h != -1)
					h++;
				if (h != -1 && bef)
					h += 4;
			}
			bef = a;
		}
		cout << h << '\n';
	}
}