#include<bits/stdc++.h>
//This code is written by Itst
using namespace std;

int main(){
	int a , b , c , d , e , f;
	cin >> a >> b >> c >> d >> e >> f;
	if(a > d || a + b > d + e || a + b + c > d + e + f)
		puts("NO");
	else
		puts("YES");
	return 0;
}