#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int	num[4] , cou = 0;
	cin >> num[0] >> num[1] >> num[2] >> num[3];
	sort(num , num + 4);
	for(int i = 0 ; i < 3 ; i++)
		if(num[i] == num[i + 1])	cou++;
	cout << cou;
	return 0;
}