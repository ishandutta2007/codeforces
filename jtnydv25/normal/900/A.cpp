#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define sd(x) scanf("%d", &(x))
#define F first
#define S second
int main(){
	int a = 0, b = 0;
	int n;
	sd(n);
	for(int i = 1; i <= n; i++){
		int x, y;
		sd(x); sd(y);
		if(x > 0) a++;
		else b++;
	}
	if(min(a, b) <= 1) printf("Yes\n");
	else printf("No\n");
}