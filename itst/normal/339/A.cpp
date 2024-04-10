#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , pot[4] = {0} , i = 1;
	while(cin >> n)	pot[n]++;
	while(!pot[i])	i++;
	cout << i;
	pot[i]--;
	for( ; i <= 3 ; i++)
		for( ; pot[i] ; pot[i]--)
			cout << "+" << i;
	return 0;
}