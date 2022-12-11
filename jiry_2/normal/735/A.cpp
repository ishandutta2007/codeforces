#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
char ch[110];
int n,K;
int main(){
	scanf("%d%d",&n,&K);
	scanf("%s",ch+1);
	int s=0,t=0;
	for (int i=1;i<=n;i++) if (ch[i]=='G') s=i; else if (ch[i]=='T') t=i;
	if (s>t) swap(s,t);
	if ((t-s)%K){
		printf("NO\n"); return 0;
	}
	for (int i=s;i<=t;i+=K)
		if (ch[i]=='#'){
			printf("NO\n"); return 0;
		}
	printf("YES\n");
	return 0;
}