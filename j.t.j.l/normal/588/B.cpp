#include<bits/stdc++.h>

using namespace std;

int main(){
	long long n;
	cin>>n;
	long long ans = 1;
	for(long long i = 2; i * i <= n; i++){
		if (n % i == 0){
			ans *= i;
			while(n % i == 0)
				n /= i;
		}
	}
	ans *= n;
	cout << ans <<endl;
	return 0;
}