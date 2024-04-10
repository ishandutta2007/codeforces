#include<bits/stdc++.h>
#define LL long long
#define LD long double
using namespace std;
const LL P=998244353;
const int N=3e5+10;
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

int h,w;
int mp[25][25];

void MAIN(){
	memset(mp,0,sizeof(mp));
	scanf("%d%d",&h,&w);
	mp[1][1]=1;
	for(int i=2;i<=w;++i){
		if(mp[1][i-1]==0) mp[1][i]=1;
	}
	for(int i=2;i<=h;++i){
		if(mp[i-1][1]==0&&mp[i-1][2]==0){
			mp[i][1]=1;
		}
		if(mp[i-1][w]==0&&mp[i-1][w-1]==0){
			mp[i][w]=1;
		}
	}
	for(int i=2;i<w;++i){
		if(mp[h][i-1]==0&&mp[h-1][i-1]==0&&mp[h-1][i+1]==0&&mp[h][i+1]==0) mp[h][i]=1;
	}
	for(int i=1;i<=h;++i){
		for(int j=1;j<=w;++j) printf("%d",mp[i][j]);
		puts("");
	}
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