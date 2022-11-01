#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n , limT , cou;
	cin >> n >> limT;
	cou = 2 * n - 2;
	limT -= 10 * n - 10;
	while(n)
	{
		int a;
		cin >> a;
		limT -= a;
		n--;
	}
	cout << (limT >= 0 ? cou + limT / 5 : -1);
	return 0;
}