#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int a , b , cou = 0;
	cin >> a >> b;
	for(int i = 1 ; i <= min(a , b) ; i++)
		if(b % i == 0  && b / i <= a)	cou++;
	cout << cou;
	return 0;
}