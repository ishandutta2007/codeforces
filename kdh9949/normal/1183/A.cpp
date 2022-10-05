#include <bits/stdc++.h>
using namespace std;

int n;

int f(int x){
	if(!x) return 0;
	return f(x/10) + x%10;
}

int main(){
	scanf("%d", &n);
	while(1){
		if(f(n) % 4) n++;
		else{ printf("%d\n", n); break; }
	}
}