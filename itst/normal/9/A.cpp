#include<bits/stdc++.h>
using namespace std;
int GCD(int a , int b)
{
	if(a < b)	swap(a , b);
	if(!b || a % b == 0)	return b;
	else	return GCD(b , a % b);
}
int main(){
	int a , b;
	cin >> a >> b;
	a = 7 - max(a , b);
	if(a <= 0)	cout << "0/1";
	else    if(a >= 6)  cout << "1/1";
	else	cout << a / GCD(a , 6) << "/" << 6 / GCD(a , 6);
	return 0;
}