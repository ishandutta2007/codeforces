#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , m;
	double minN = 2147483647;
	for(cin >> n >> m ; n ; n--)
	{
		int a , b;
		cin >> a >> b;
		minN = min(minN , a * 1.0 / b);
	}
	printf("%.8f" , minN * m);
	return 0;
}