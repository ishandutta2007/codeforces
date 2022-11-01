#include<bits/stdc++.h>
using namespace std;
int a[101] = {0 , 1 , 2 , 4 , 6};
int main(){
	int n;
	cin >> n;
	for(int i = 5 ; i <= n ; i++)
		a[i] = a[i - 1] * 2 - a[i - 3] * 2 + a[i - 4];
	cout << a[n];
	return 0;
}