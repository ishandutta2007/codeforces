#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , sum = 0;
	cin >> a >> b;
	for(int i = 0 ; i < a ; i++)
	{
		int c;
		cin >> c;
		if(c > b)	sum += 2;
		else	sum++;
	}
	cout << sum;
	return 0;
}