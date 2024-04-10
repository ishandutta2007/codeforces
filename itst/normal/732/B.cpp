#include<bits/stdc++.h>
using namespace std;
int num[501];
int main()
{
	ios::sync_with_stdio(false);
	int n , k , cou = 0;
	cin >> n >> k;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> num[i];
		if(i && num[i] + num[i - 1] < k)
		{
			cou += k - (num[i] + num[i - 1]);
			num[i] += k - (num[i] + num[i - 1]);
		}
	}
	cout << cou << endl;
	for(int i = 0 ; i < n ; i++)
		cout << num[i] << " ";
	return 0;
}