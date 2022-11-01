#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , max , maxI , min , minI , a;
	cin >> n >> a;
	max = min = a;
	maxI = minI = 0;
	for(int i = 1 ; i < n ; i++)
	{
		cin >> a;
		if(a > max)
		{
			max = a;
			maxI = i;
		}
		if(a <= min)
		{
			min = a;
			minI = i;
		}
	}
	if(maxI > minI)	minI++;
	cout << maxI + n - 1 - minI;
	return 0;
}