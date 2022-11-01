#include <bits/stdc++.h>
#define maxn 100086

using namespace std;

int t;
int n;
int a[2][2];
char s[maxn];

int main(){
	scanf("%d", &t);
	while(t--){
		scanf("%d%s", &n, s + 1);
		memset(a, 0, sizeof(a));
		for(int i = 1;i <= n;i++) a[i & 1][(s[i] - '0') & 1]++;
		if(a[1][0] + a[1][1] > a[0][0] + a[0][1]){
			if(a[1][1]) puts("1");
			else puts("2");
		}else{
			if(a[0][0]) puts("2");
			else puts("1");
		}
	}
}