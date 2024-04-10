#include<bits/stdc++.h>
using namespace std;
int main(){
	int n , pot1 = 0 , pot2 = 0;
	for(cin >> n ; n ; n--)
	{
		int b;
		cin >> b;
		b == 1 ? pot1++ : pot2++;
	}
	cout << min(pot1 , pot2) + (pot1 - min(pot1 , pot2)) / 3;
	return 0;
}