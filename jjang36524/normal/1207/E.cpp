#include <iostream>
#include <vector>
#include <string.h>
#define ma 16384
using namespace std;
vector<int>possible;
int whatitmeans[1<<14];
int main()
{
	int i;
	memset(whatitmeans, -1, sizeof(whatitmeans));
	cout << '?' << ' ';
	for (i = 0; i < 100; i++)
	{
		cout << i << ' ';
	}
	cout << '\n';
	fflush(stdout);
	int ans;
	cin >> ans;
	for (i = 0; i < 100; i++)
	{
		possible.push_back(ans^i);
	}
	cout << '?'<<' ';
	int count=0;
	for (i = 100; i < ma; i++)
	{
		if (count == 100)
			break;
		int j;
		for (j = 0; j < 100; j++)
		{
			if (whatitmeans[i^possible[j]] != -1 && whatitmeans[i^possible[j]] != possible[j])
				goto fail;
		}
		for (j = 0; j < 100; j++)
		{
			whatitmeans[i^possible[j]] = possible[j];
		}
		count++;
		cout << i << ' ';
	fail:
		int d;
	}
	cout << '\n';
	fflush(stdout);
	cin >> ans;
	cout <<'!'<<' '<< whatitmeans[ans];
	return 0;
}