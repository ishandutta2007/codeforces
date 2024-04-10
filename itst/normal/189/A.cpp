#include<bits/stdc++.h>
using namespace std;
int vis[4001];
int main()
{
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0 ; i <= 2 ; i++)
	{
		int t;
		cin >> t;
		for(int j = 0 ; j <= n - t ; j++)
			if(!j || vis[j])
				vis[j + t] = max(vis[j + t] , vis[j] + 1);
	}
	cout << vis[n];
	return 0;
}