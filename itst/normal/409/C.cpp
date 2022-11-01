#include<bits/stdc++.h>
using namespace std;
int main(){
	int a , b , c , d , e;
	cin >> a >> b >> c >> d >> e;
	cout << min(min(min(min(a , b) , c / 2) , d / 7) , e / 4);
	return 0;
}