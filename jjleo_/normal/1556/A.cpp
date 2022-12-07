#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, c, d;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &c, &d);
		if(c == 0 && d == 0) puts("0");
		else if(c == d) puts("1");
		else if((c + d) & 1) puts("-1");
		else puts("2"); 
	}
}