#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , n;
	cin >> a >> n;
	if(n == 0)
		if(a == 1)	cout << "0 0";
		else	cout << "-1 -1";
	else
	{
		if(a * 9 < n)
		{
			cout << "-1 -1";
			return 0;
		}
		int n1 = n;
		for(int i = 0 ; i < a ; i++)
			if((a - i - 1) * 9 > n)
				if(i)	cout << 0;
				else{
					cout << 1;
					n--;
				}
			else
			{
				cout << n - (a - i - 1) * 9;
				n -= n - (a - i - 1) * 9;
			}
		cout << " ";
		for(int i = 0 ; i < a ; i++)
			if(n1 <= 9)
			{
				cout << n1;
				n1 = 0;
			}
			else
			{
				cout << 9;
				n1 -= 9;
			}
	}
	return 0;
}