#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 0 , b = 0 , n , numa = 0 , numb = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int num;
		cin >> num;
		if(!a)	a = num;
		if(a == num)	numa++;
		else
		{
			if(!b)	b = num;
			if(b == num)	numb++;
			else
			{
				cout << "NO";
				return 0;
			}
		}
	}
	if(!b || !a || numa != numb)
		cout << "NO";
	else
		cout << "YES" << endl << a << " " << b;
	return 0;
}