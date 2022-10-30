#include<bits/stdc++.h>
using namespace std;
int main(){
	long long m , n , t;
	cin >> m >> n >> t;
	cout << (m / t + (m % t != 0)) * (n / t + (n % t != 0));
	return 0;
	//
}