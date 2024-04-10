#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 1005;
const int NL = 8;

int n;
char seats[MaxN][NL];

int main()
{
	cin >> n;

	bool found = false;
	for (int i = 1; i <= n; ++i)
	{
		cin >> seats[i];
		if (!found && seats[i][0] == 'O' && seats[i][1] == 'O')
			found = true, seats[i][0] = seats[i][1] = '+';
		if (!found && seats[i][3] == 'O' && seats[i][4] == 'O')
			found = true, seats[i][3] = seats[i][4] = '+';
	}

	if (!found)
		cout << "NO";
	else
	{
		cout << "YES\n";
		for (int i = 1; i <= n; ++i)
			cout << seats[i] << endl;
	}

	return 0;
}