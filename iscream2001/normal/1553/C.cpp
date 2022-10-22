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
int check(){
	int x=0,y=0,X=5,Y=5;
	for(int i=1;i<=10;++i){
		if(i&1){
			--X;
			if(t[i]=='1') ++x;
		}
		else{
			--Y;
			if(t[i]=='1') ++y;
		}
		if(x+X<y) return i;
		if(y+Y<x) return i;
	}
	return 10;
}
void MAIN(){
	scanf("%s",s+1);n=10;
	int ans=10;
	for(int i=1;i<=n;++i){
		if(s[i]=='1'||s[i]=='0') t[i]=s[i];
		else{
			if(i&1) t[i]='1';
			else t[i]='0';
		}
	}
	ans=min(ans,check());
	for(int i=1;i<=n;++i){
		if(s[i]=='1'||s[i]=='0') t[i]=s[i];
		else{
			if(i&1) t[i]='0';
			else t[i]='1';
		}
	}
	ans=min(ans,check());
	printf("%d\n",ans);
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