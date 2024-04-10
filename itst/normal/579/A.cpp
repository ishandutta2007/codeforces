#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , cou = 0;
	for(cin >> n ; n ; n /= 2)
		if(n % 2)	cou++;
	cout << cou;
	return 0;
}