#include<bits/stdc++.h>
using namespace std;
int vis[2];
int main(){
	int n , day = 0;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		cin >> vis[0] >> vis[1];
		if(day < vis[0])	day = vis[0] + 1;
		else	day = ceil((day - vis[0]) * 1.0 / vis[1]) * vis[1] + vis[0] + 1;
	}
	cout << --day;
	return 0;
}