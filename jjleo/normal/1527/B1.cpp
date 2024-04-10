#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		int sum = 0;
		for(int i = 1;i <= n;i++) sum += s[i] == '0';
		if(sum == 0) puts("DRAW");
		else puts((sum & 1) && sum > 1 ? "ALICE" : "BOB");
	}
}