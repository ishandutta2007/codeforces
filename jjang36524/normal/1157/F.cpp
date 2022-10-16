#include <iostream>
using namespace std;
int arr[200100];
int x, y, z;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		cin >> a;
		arr[a]++;
	}
	int cou = 0, st = 1;
	for (i = 1; i <=200001; i++)
	{
		if (arr[i] >= 2)
		{
			cou += arr[i];
		}
		else
		{
			if (arr[i] == 1)
				cou++;
			if (arr[st - 1] == 1)
			{
				cou++;
				st--;
			}
			if (cou > x)
			{
				x = cou;
				y = st;
				z = i + arr[i]-1;
			}
			cou = 0;
			st = i+1;
		}
	}
	cout << x << '\n';
	for (i = y; i <= z; i++)
		cout << i << ' ';
	for (i = z; i >= y; i--)
	{
		int j;
		for (j = 1; j < arr[i]; j++)
		{
			cout << i << ' ';
		}
	}
}