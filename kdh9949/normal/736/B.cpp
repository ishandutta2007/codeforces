#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;

bool f(int n){
	if(n % 2 == 0) return false;
	n -= 2;
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0) return true;
	}
	return false;
}

int main(){
	scanf("%d", &n);
	for(int i = 2; i * i <= n; i++){
		if(n % i == 0){
			printf("%d\n", f(n) ? 3 : 2);
			return 0;
		}
	}
	puts("1");
	return 0;
}