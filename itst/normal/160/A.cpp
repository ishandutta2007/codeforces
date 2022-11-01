#include<bits/stdc++.h>
using namespace std;
int num[101];
int main()
{
	std::ios::sync_with_stdio(false);
	int i , n , sum = 0 , sum1 = 0;
	cin >> n;
	for(i = 0 ; i < n ; i++)
	{
		cin >> num[i];
		sum += num[i];
	}
	sort(num , num + n);
	for(i = n - 1 ; sum1 * 2 <= sum && i >= 0 ; i--)
		sum1 += num[i];
	cout << n - i - 1;
	return 0;
}