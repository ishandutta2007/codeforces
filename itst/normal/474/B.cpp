#include<bits/stdc++.h>
using namespace std;
int vis[1000001];
int main()
{
	int dirN = 1 , n , m;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		int a;
		for(cin >> a ; a ; a--)	vis[dirN++] = i;
	}
	for(cin >> m ; m ; m--)
	{
		int a;
		cin >> a;
		cout << vis[a] << endl;
	}
	return 0;
}