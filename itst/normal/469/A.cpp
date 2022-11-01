#include<bits/stdc++.h>
using namespace std;
bool vis[101];
int main()
{
	std::ios::sync_with_stdio(false);
	int l , a , b;
	cin >> l >> a;
	for(int i = 0 ; i < a ; i++)
	{
		cin >> b;
		vis[b] = 1;
	}
	cin >> b;
	for(int i = 0 ; i < b ; i++)
	{
		cin >> a;
		vis[a] = 1;
	}
	for(int i = 1 ; i <= l ; i++)
		if(!vis[i])	
		{
			cout << "Oh, my keyboard!";
			return 0;
		}
	cout << "I become the guy.";
	return 0;
}