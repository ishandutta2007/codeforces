#include<bits/stdc++.h>
using namespace std;
int pot[10001];
bool vis[10001];
int main()
{
	std::ios::sync_with_stdio(false);
	int s , n , maxN = 0;
	cin >> s >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int a , b;
		cin >> a >> b;
		pot[a] += b;
		vis[a] = 1;
		maxN = max(maxN , a);
	}
	for(int i = 1 ; i <= maxN && s <= maxN ; i++)
		if(vis[i] && i >= s)
		{
			cout << "NO";
			return 0;
		}
		else	s += pot[i];
	cout << "YES";
	return 0;
}