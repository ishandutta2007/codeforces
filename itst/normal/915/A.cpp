#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , k , num , minN = 2147483647;
	for(cin >> n >> k ; n ; n--)
	{
		cin >> num;
		if(k % num == 0)
			minN = min(minN , k / num);
	}
	cout << minN;
	return 0;
}