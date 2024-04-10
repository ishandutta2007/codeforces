#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int num[3];
	cin >> num[0] >> num[1] >> num[2];
	if(num[0] * num[1] * num[2] == 1)
	{
		cout << 3;
		return 0;
	}
	if(num[0] == 1)	num[1]++;
	if(num[1] == 1)
		if(num[2] < num[0])	num[2]++;
		else	num[0]++;
	if(num[2] == 1)	num[1]++;
	cout << num[0] * num[1] * num[2];
	return 0;
}