#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , num = 0 , minN = 101;
	for(cin >> n ; n ; n--)
	{
		int a , p;
		cin >> a >> p;
		minN = min(minN , p);
		num += a * minN;
	}
	cout << num;
	return 0;
}