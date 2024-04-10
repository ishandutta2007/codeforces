#include<bits/stdc++.h>
using namespace std;
const int M=5e5+9;
int _f[2][M<<1],*f[2];
char s[M];
int main(){
	int T;
	f[0]=_f[0]+M;
	f[1]=_f[1]+M;
	for(scanf("%d",&T);T;--T){
		scanf("%s",s+1);
		int n=strlen(s+1);
		for(int i=1,x=0;i<=n;++i)f[s[i]&1][x]++,x+=(s[i]&1)?1:-1;
		for(int i=1,x=0;i<=n;++i)((f[0][x]&&f[1][x-1])||!f[1][x])?(f[0][x]--,x--,putchar('0')):(f[1][x]--,x++,putchar('1'));
		puts("");
	}
	return 0;
}