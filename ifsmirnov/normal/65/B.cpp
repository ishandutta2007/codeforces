#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int setDigit (int x, int digit, int pos)
{
	if (pos == 0) x = (x/10)*10 + digit;
	else if (pos == 1) x = (x/100)*100 + digit*10 + x%10;
	else if (pos == 2) x = (x/1000)*1000 + digit*100 + x%100;
	else if (pos == 3) x = digit*1000 + x%1000;
	return x;
};

int a[1001];
int n;

bool solve();

int mod[50];

int main()
{
/*	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);*/
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	
	if (solve())
	{	
		for (int i = 1; i <= n; i++) cout<<a[i] << endl;
	}
	else
		cout<<"No solution";

	return 0;
};

bool solve()
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= 9; j++) mod[j] = setDigit(a[i], j, 0);
		for (int j = 0; j <= 9; j++) mod[j+10] = setDigit(a[i], j, 1);
		for (int j = 0; j <= 9; j++) mod[j+20] = setDigit(a[i], j, 2);
		for (int j = 0; j <= 9; j++) mod[j+30] = setDigit(a[i], j, 3);

//		for (int j = 0; j < 32; j++) cout << mod[j] << " ";
		
		sort(mod, mod+40);

//		cout<<endl;

		a[i] = -1;
		for (int j = 0; j < 40; j++)
		{
			if (mod[j] >= 1000 && mod[j] <= 2011 && mod[j] >= a[i-1])
			{
				a[i] = mod[j];
				break;
			}
		}
		if (a[i] == -1)
			return false;
	}
	return true;
};