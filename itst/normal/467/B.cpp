#include<bits/stdc++.h>
using namespace std;
int vis[1000];
inline bool ifD(int a , int b , int c)
{
	int d = a ^ b;
	while(d && c >= 0)
	{
		if(d & 1)	c--;
		d >>= 1;
	}
	if(c >= 0)	return true;
	else	return false;
}
int main()
{
	int a , n , m , k , cou = 0;
	cin >> n >> m >> k;
	for(int i = 0 ; i < m ; i++)	cin >> vis[i];
	cin >> a;
	for(int i = 0 ; i < m ; i++)	cou += ifD(a , vis[i] , k);
	cout << cou;
	return 0;
}