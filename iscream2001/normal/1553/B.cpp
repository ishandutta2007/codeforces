#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=5e5+10;
const int INF=1e9;
int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
void print(LL x){
    if(x>9) print(x/10);
    putchar(x%10+'0');
}
void pls(LL &x,LL y){
    x+=y;if(x>=P)x-=P;
}
void init(){
	return;
}

int n,m;
char s[510],t[1020];
void MAIN(){
	scanf("%s",s+1);n=strlen(s+1);
	scanf("%s",t+1);m=strlen(t+1);
	bool f=0,F;
	for(int i=1;i<=n&&f==0;++i){
		for(int j=1;j<=m&&f==0;++j){
			F=1;
			for(int k=j,o=i;k>=1;--k,--o){
				if(o<1){
					F=0;
					break;
				}
				if(s[o]!=t[k]){
					F=0;
					break;
				}
			}
			for(int k=j,o=i;k<=m;++k,--o){
				if(o<1){
					F=0;
					break;
				}
				if(s[o]!=t[k]){
					F=0;
					break;
				}
			}
			if(F==1) f=1;
		}
	}
	if(!f) puts("NO");
	else puts("YES");
	return;
}
int main(){
//	freopen("1.in","r",stdin);
	init();
	int ttt=1;scanf("%d",&ttt);
	while(ttt--) MAIN();
	return 0;	
}
/*
*/