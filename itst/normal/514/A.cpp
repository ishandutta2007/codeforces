#include<bits/stdc++.h>
using namespace std;
int num[19];
int main()
{
	long long x , cou = 1;
	cin >> x;
	while(x)
	{
		if(x % 10 >= 5 && x - 9)	num[cou] = 9 - x % 10;
		else	num[cou] = x % 10;
		x /= 10;
		cou++;
	}
	cou--;
	while(cou)	cout << num[cou--];
	return 0;
}