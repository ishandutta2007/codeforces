#include<bits/stdc++.h>
using namespace std;
int pot[1001];
int main()
{
	ios::sync_with_stdio(false);
	int n , cou = 0 , maxN = 0;
	for(cin >> n ; n ; n--)
	{
		int a;
		cin >> a;
		pot[a]++;
	}
	for(int i = 0 ; i <= 1000 ; i++)
		if(pot[i])
		{
			cou++;
			maxN = max(maxN , pot[i]);
		}
	cout << maxN << " " << cou;
	return 0;
}