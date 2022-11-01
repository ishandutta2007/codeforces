#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , x = 0 , y = 0 , z = 0;
	for(cin >> n ; n ; n--)
	{
		int a , b , c;
		scanf("%d%d%d" , &a , &b , &c);
		x += a;
		y += b;
		z += c;
	}
	if(x || y || z)
		cout << "NO";
	else
		cout << "YES";
	return 0;
}