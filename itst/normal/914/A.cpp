#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , maxN = -1000001;
	cin >> n;
	for(int i = 0 ; i < n ; i++)
	{
		int num;
		cin >> num;
		if((int)sqrt(num) != sqrt(num))
			maxN = max(maxN , num);
	}
	cout << maxN;
	return 0;
}