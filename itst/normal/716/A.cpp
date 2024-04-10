#include<bits/stdc++.h>
using namespace std;
int main()
{
	int nowT = 0 , n , c , cou = 0;
	cin >> n >> c;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		if(a - nowT > c)	cou = 0;
		nowT = a;
		cou++;
	}
	cout << cou;
	return 0;
}