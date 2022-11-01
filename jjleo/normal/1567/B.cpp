#include <bits/stdc++.h>
#define maxn 300086

using namespace std;

int t;
int sum[maxn];
int a, b;

int main(){
	for(int i = 1;i < maxn;i++) sum[i] = sum[i - 1] ^ i;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &a, &b);
		if(sum[a - 1] == b) printf("%d\n", a);
		else if(sum[a] == b) printf("%d\n", a + 2);
		else printf("%d\n", a + 1);
	} 
}