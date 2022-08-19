#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long lint;

int isprime(int x){
	for(int i=2; i*i<=x; i++){
		if(x%i == 0) return 0;
	}
	return 1;
}


int main(){
	int n;
	cin >> n;
	if(n <= 2) printf("1\n");
	else printf("2\n");
	for(int i=2; i<=n+1; i++){
		printf("%d ", 2 - isprime(i));
	}
}