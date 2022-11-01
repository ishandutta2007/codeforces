#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	string s;
	cin >> s;
	int ifAB = 0 , ifBA = 0;
	for(int i = 0 ; i + 1 < s.size() ; i++)
		if(string(s , i , 2) == "AB")
		{
			if(ifBA > 1 || ifBA == 1 && string(s , i - 1 , 2) != "BA")
			{
				cout << "YES";
				return 0;
			}
			ifAB++;
		}
		else	if(string(s , i , 2) == "BA")
		{
			if(ifAB > 1 || ifAB == 1 && string(s , i - 1 , 2) != "AB")
			{
				cout << "YES";
				return 0;
			}
			ifBA++;
		}
	cout << "NO";
	return 0;
}