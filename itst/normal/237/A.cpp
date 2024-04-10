#include<bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n , nowH = -1 , nowS = -1 , num = 0 , maxN = 0;
	for(cin >> n ; n ; n--)
	{
		int a , b;
		cin >> a >> b;
		if(a == nowH && b == nowS)	num++;
		else{
			maxN = max(maxN , num);
			num = 1;
			nowH = a;
			nowS = b;
		}
	}
	cout << max(maxN , num);
	return 0;
}