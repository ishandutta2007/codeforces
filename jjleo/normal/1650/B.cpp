#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t, l, r, a;

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%d%d", &l, &r, &a);
		if(l / a == r / a) printf("%d\n", r / a + r % a);
		else printf("%d\n", max(r / a - 1 + a - 1, r / a + r % a));
	}
}