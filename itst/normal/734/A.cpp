#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , wA = 0 , wD = 0;
	for(cin >> n ; n ; n--)
	{
		char c;
		cin >> c;
		if(c == 'A')	wA++;
		else	wD++;
	}
	if(wA > wD)	cout << "Anton";
	else	if(wA == wD)	cout << "Friendship";
	else	cout << "Danik";
	return 0;
}