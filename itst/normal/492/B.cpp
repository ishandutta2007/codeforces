#include<bits/stdc++.h>
using namespace std;
int vis[2000];
int main()
{
	double maxN;
	int n , l;
	cin >> n >> l;
	for(int i = 0 ; i < n ; i++)	cin >> vis[i];
	sort(vis , vis + n);
	maxN = max(vis[0] , l - vis[n - 1]);
	for(int i = 1 ; i < n ; i++)	maxN = max(maxN , (vis[i] - vis[i - 1]) / 2.0);
	printf("%.10f" , maxN);
	return 0;
}