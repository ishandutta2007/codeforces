#include<bits/stdc++.h>
using namespace std;
int charge(int i , int j , int k)
{
	if(i == 1 && j == 1 || i <= 0 || j <= 0)
		return k;
	else
		if(j == 1 || j == 2)
			charge(i - 2 , j + 1 , k + 1);
		else
			charge(i + 1 , j - 2 , k + 1);
}
int main(){
	int a1 , a2;
	cin >> a1 >> a2;
	cout << charge(a1 , a2 , 0);
	return 0;
}