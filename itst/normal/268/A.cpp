#include<bits/stdc++.h>
using namespace std;
int uni[31][2];
int main()
{
	std::ios::sync_with_stdio(false);
	int n , cou = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> uni[i][0] >> uni[i][1];
		for(int j = i - 1 ; j + 1 ; j--)
		{
			if(uni[i][0] == uni[j][1])	cou++;
			if(uni[i][1] == uni[j][0])	cou++;
		}
	}
	cout << cou;
	return 0;
}