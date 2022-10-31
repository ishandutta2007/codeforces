#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
#include<set>

#define ll long long

using namespace std;

int n, y;
ll x;
char ok;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
	 	scanf("%I64d", &x);
	 	y = (int)sqrt(x + 0.0);
	 	if (y *1ll* y == x) {
	 		ok = 0;
			for (int j = 2; j * j <= y; j++)
				if (y % j == 0) {
				 	ok = 1;
				 	break;
				}
		  	if (ok || y == 1) {
		  	 	printf("NO\n");
		  	} else {
		  	 	printf("YES\n");
		  	}
	 	} else {
	 	 	printf("NO\n");
	 	}
    }

}