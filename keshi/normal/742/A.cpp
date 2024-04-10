#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,a[5]={1,8,4,2,6};
	cin >> n;
	cout << a[(n-1)%4+1];
	return 0;
}