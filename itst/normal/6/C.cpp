#include<bits/stdc++.h>
using namespace std;
int t[100051] , tA[100051] , tB[100051];
int main(){
	int n;
	cin >> n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin >> t[i];
		tA[i] = tA[i - 1] + t[i - 1];
	}
	for(int i = n ; i ; i--)
	{
		tB[i] = tB[i + 1] + t[i + 1];
		if(tA[i] <= tB[i])
		{
			cout << i << " " << n - i;
			return 0;
		}
	}
}