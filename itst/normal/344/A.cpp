#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	string s , sNow;
	int cou = 1 , n;
	cin >> n >> sNow;
	for(int i = 1 ; i < n ; i++)
	{
		cin >> s;
		if(s != sNow)
		{
			sNow = s;
			cou++;
		}
	}
	cout << cou;
	return 0;
}