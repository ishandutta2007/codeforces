#include<bits/stdc++.h>
using namespace std;
int num[5][5];
int main()
{
	std::ios::sync_with_stdio(false);
	for(int i = 0 ; i < 5 ; i++)
		for(int j = 0 ; j < 5 ; j++)
		{
			cin >> num[i][j];
			if(num[i][j] == 1)
			{
				cout << abs(i - 2) + abs(j - 2);
				return 0;
			}
		}
	return 0;
}