#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , cou = 0 , maxN = -1 , num = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a;
		cin >> a;
		if(a)	
		{
			cou++;
			num = num ? num - 1 : 0;
		}
		else	maxN = max(maxN , ++num);
	}
	cout << maxN + cou;
	return 0;
}