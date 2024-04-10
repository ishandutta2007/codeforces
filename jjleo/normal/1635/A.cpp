#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, n, x;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		int y = 0;
		while(n--) scanf("%d", &x), y |= x;
		printf("%d\n", y);
	}
}