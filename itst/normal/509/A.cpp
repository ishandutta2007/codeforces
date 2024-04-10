#include<bits/stdc++.h>
using namespace std;
int num[11][11];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
		num[1][i] = 1;
	for(int i = 2 ; i <= n ; i++)
		for(int j = 1 ; j <= n ; j++)
			num[i][j] = num[i - 1][j] + num[i][j - 1];
	cout << num[n][n];
	return 0;
}