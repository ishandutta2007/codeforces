#include<bits/stdc++.h>
using namespace std;
int vis[251];
int main(){
	int t;
	for(cin >> t ; t ; t--)
	{
		int n , k , maxN = 0;
		cin >> n >> k;
		for(int i = 1 ; i <= n ; i++)
			vis[i] = 201;
		for(int i = 0 ; i < k ; i++)
		{
			int a;
			cin >> a;
			for(int j = 1 ; j <= n ; j++)
				vis[j] = min(vis[j] , abs(a - j) + 1);
		}
		for(int i = 1 ; i <= n ; i++)
			maxN = max(maxN , vis[i]);
		cout << maxN;
		if(t - 1)	cout << endl;
	}
	return 0;
}