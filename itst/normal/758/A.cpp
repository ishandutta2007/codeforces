#include<bits/stdc++.h>
using namespace std;
int num[101];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , maxN = 0 , sum = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> num[i];
		maxN = max(maxN , num[i]);
	}
	for(int i = 0 ; i < n ; i++)	sum += maxN - num[i];
	cout << sum;
	return 0;
}