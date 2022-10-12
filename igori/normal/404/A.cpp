#include <iostream>
#include <string>

using namespace std;


#define re return

int n, cnt[300];
string a[2000];

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		for (int j = 0; j < n; j++)
		{
			cnt[a[i][j]]++;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i][i] != a[i - 1][i - 1])
		{
			cout << "NO";
			re 0;
		}
	}
	for (int i = 1; i < n; i++)
	{
		if (a[i][n - i - 1] != a[i - 1][n - i])
		{
			cout << "NO";
			re 0;
		}
	}
	int meaning = 0, we = 0;
	for (int i = 0; i < 300; i++)
	{
		meaning += (cnt[i] > 0);
		we += (cnt[i] == 2 * n - 1 && i == a[0][0]);
	}
	if (meaning == 2 && we == 1)
	{
		cout << "YES";
		re 0;
	}
	cout << "NO";
}