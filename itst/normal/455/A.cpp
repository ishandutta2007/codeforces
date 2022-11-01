#include<bits/stdc++.h>
using namespace std;
long long num[100001] , vis[100001];
int main()
{
	ios::sync_with_stdio(false);
	int n , maxN = 0;
	for(cin >> n ; n ; n--)
	{
		int a;
		cin >> a;
		num[a]++;
		maxN = max(maxN , a);
	}
	vis[1] = num[1];
	for(int i = 2 ; i <= maxN ; i++)
		vis[i] = max(vis[i - 1] , vis[i - 2] + num[i] * i);
	cout << vis[maxN];
	return 0;
}