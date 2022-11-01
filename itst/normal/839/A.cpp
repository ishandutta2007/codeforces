#include<bits/stdc++.h>
using namespace std;
int main(){
	int a = 0 , n , k;
	cin >> n >> k;
	if(k / n > 8)
		cout << -1;
	else
	{
		int i = 0;
		for(; i < n && k > 0 ; i++)
		{
			int b;
			cin >> b;
			a += b;
			k -= min(a , 8);
			a -= min(a , 8);
		}
		if(i == n && k > 0)
			cout << -1;
		else
			cout << i;
	}
	return 0;
}