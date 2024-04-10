#include<bits/stdc++.h>
using namespace std;
long long num[500001];
int main()
{
	ios::sync_with_stdio(false);
	long long sum = 0 , cou = 0 , couI = 0;
	int n , i;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		sum += a;
		num[i] = num[i ? i - 1 : 0] + a;
	}
	if(sum % 3)
	{
		cout << 0;
		return 0;
	}
	sum /= 3;
	for(i = 0 ; i < n - 1 ; i++)
	{
		if(num[i] == sum * 2)	cou += couI;
		if(num[i] == sum)	couI++;
	}
	cout << cou;
	return 0;
}