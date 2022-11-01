#include<bits/stdc++.h>
using namespace std;
int main()
{
	std::ios::sync_with_stdio(false);
	int N , cou = 0;
	cin >> N;
	for(int i = 0 ; i < N ; i++)
	{
		int a , b , c;
		cin >> a >> b >> c;
		if(a + b + c >= 2)	cou++;
	}
	cout << cou;
	return 0;
}