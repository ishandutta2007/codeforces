#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n , k = 0;
	cin >> n;
	while(n){
		if(n % 10 == 4 || n % 10 == 7)
			k++;
		n /= 10;
	}
	cout << (k == 4 || k == 7 ? "YES" : "NO");
	return 0;
}