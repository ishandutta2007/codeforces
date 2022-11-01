#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , c , d , e , cou = 0;
	cin >> a >> b >> c >> d >> e;
	for(int i = 1 ; i <= e ; i++)
		if(i % a && i % b && i % c && i % d)	cou++;
	cout << e - cou;
	return 0;
}