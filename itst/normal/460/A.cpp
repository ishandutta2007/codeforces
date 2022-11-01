#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , i = 0 , k;
	cin >> n >> k;
	while(n)
	{
		i++;
		if(i % k)	n--;
	}
	cout << i;
	return 0;
}