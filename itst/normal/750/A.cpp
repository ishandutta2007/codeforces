#include<bits/stdc++.h>
using namespace std;
int main(){
	int a , b , i = 0;
	cin >> a >> b;
	while(b <= 240)	b += ++i * 5;
	cout << min(--i , a);
	return 0;
}