#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , m , pNow = 1 , pDes;
	long long sum = 0;
	for(cin >> n >> m ; m ; m--)
	{
		cin >> pDes;
		if(pNow > pDes)	sum += n + pDes - pNow;
		else	sum += pDes - pNow;
		pNow = pDes; 
	}
	cout << sum;
	return 0;
}