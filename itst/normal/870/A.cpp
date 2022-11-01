#include<bits/stdc++.h>
using namespace std;
int potA[10] , potB[10];
int main(){
	int n , m , minN = 10 , minM = 10;
	for(cin >> n >> m ; n ; n--)
	{
		int a;
		cin >> a;
		minN = min(minN , a);
		potA[a]++;
	}
	for( ; m ; m--)
	{
		int a;
		cin >> a;
		minM = min(minM , a);
		potB[a]++;
	}
	for(int i = 1 ; i <= 9 ; i++)
		if(potA[i] && potB[i])
		{
			cout << i;
			return 0;
		}
	cout << min(minN , minM) << max(minN , minM);
	return 0;
}