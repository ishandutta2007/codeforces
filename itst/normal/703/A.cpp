#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int n , winM = 0;
	for(cin >> n ; n ; n--)
	{
		int a , b;
		cin >> a >> b;
		if(a > b)	winM++;
		else	if(a < b)	winM--;
	}
	if(winM > 0)	cout << "Mishka";
	else	if(winM < 0)	cout << "Chris";
	else	cout << "Friendship is magic!^^";
	return 0;
}