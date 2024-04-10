#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, b, a, cb, ca;

int main(){
	scanf("%d%d%d", &n, &b, &a);
	cb = b; ca = a;
	for(int i = 0, x; i < n; i++){
		scanf("%d", &x);
		if(cb + ca == 0){ printf("%d\n", i); return 0; }
		if(!x){
			if(ca) ca--;
			else cb--;
		}
		else{
			if(cb && ca < a){ cb--; ca++; }
			else ca--;
		}
	}
	printf("%d\n", n);
}