#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main()
{
	int left,right,n, left_0, right_0,left_1,right_1;
	cin >> n;
	left_0 = left_1 = right_0 = right_1 = 0;

	for (int i = 1; i <= n; ++i)
	{
		cin >> left;
		cin >> right;
		if (left == 0)
		{
			left_0++ ;
		}
		if (left == 1)
		{
			left_1++ ;
		}
		if (right == 1)
		{
			right_1++ ;
		}
		if (right == 0)
		{
			right_0++ ;
		}
	}

	cout << min(right_0,right_1) + min(left_0 , left_1);
}