#include<bits/stdc++.h>
using namespace std;
int num[6];
int main(){
	int a , b , c , sum = 0;
	cin >> a >> b;
	b = 5 - b;
	while(a--){
		cin >> c;
		++num[c];
	}
	while(b >= 0)	sum += num[b--];
	cout << sum / 3;
	return 0;
}