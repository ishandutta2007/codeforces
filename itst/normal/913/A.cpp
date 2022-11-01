#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , m , num = 0 , k = 1;
	cin >> n >> m;
	for(int i = 0 ; i < n && m ; i++)
	{
		num += m % 2 * k;
		k *= 2;
		m /= 2;
	}
	cout << num;
	return 0;
}