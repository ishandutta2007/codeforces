#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
#define forn(i, n) for (int i = 0; i < (int)(n); i++)
string a[10]={"Sheldon", "Leonard", "Penny", "Rajesh", "Howard"};

int maxbit (int a)
{
	int c = 0;
	while (a)
	{
		c++;
		a >>= 1;
	}
	return c;
};

int main()
{
	//freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	n--;
	
	int len = 1<<(maxbit(n/5+1)-1);
	int fi = ((1<<(maxbit(n/5+1)-1)) - 1) * 5;

	cout << a[(n-fi) / len];
	
	return 0;
};