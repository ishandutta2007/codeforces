#include<bits/stdc++.h>
using namespace std;
int pot[1001];
int main(){
	int n , m , minN = 1001;
	for(cin >> n >> m ; m ; m--)
	{
		int a;
		cin >> a;
		pot[a]++;
	}
	for( ; n ; n--)
		minN = min(minN , pot[n]);
	cout << minN;
	return 0;
}