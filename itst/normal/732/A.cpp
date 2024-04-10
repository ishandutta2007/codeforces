#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int k , n;
	cin >> k >> n;
	for(int i = 1 ; i <= 10 ; i++)
		if(k * i % 10 == n || k * i % 10 == 0)
		{
			cout << i;
			return 0;
		}
}