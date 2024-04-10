#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , cou = 0 , sum = 0;
	for(cin >> n ; n ; n--)
	{
		int a;
		cin >> a;
		if(a + 1)	sum += a;
		else	if(sum)	sum--;
		else	cou++;
	}
	cout << cou;
	return 0;
}