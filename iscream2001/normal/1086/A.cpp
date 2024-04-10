#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB long double
#define pa pair<LL,int>
#define ctz __builtin_ctz
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}

inline void Out(int x){
    if(x>9) Out(x/10);
    putchar(x%10+'0'); 
}

LL qpow(LL x,LL y,LL P){
    LL re=1;
    while(y){
        if(y&1) re=re*x%P;
        x=x*x%P;y>>=1;	
    } 
    return re;
}
struct node{
	int x,y;
}a[5];
bool cmp(node A,node B){
	return A.x<B.x;
}
int mn=10000,mx=-1;
int js=0;
bool vis[2000][2000];
int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
    for(int i=1;i<=3;++i){
    	cin>>a[i].x>>a[i].y;
    	mx=max(mx,a[i].y);
    	mn=min(mn,a[i].y);
	}
	sort(a+1,a+3+1,cmp);
	if(a[1].x==a[2].x&&a[1].x==a[3].x){
		for(int i=mn;i<=mx;++i)
			if(!vis[a[2].x][i]){
				vis[a[2].x][i]=1;
				++js;
			}
	}
	else{
		for(int i=mn;i<=mx;++i)
			if(!vis[a[2].x][i]){
				vis[a[2].x][i]=1;
				++js;
			}
		for(int i=a[1].x;i<=a[2].x;++i){
			if(!vis[i][a[1].y]){
				vis[i][a[1].y]=1;
				++js;
			}
		}
		for(int i=a[2].x;i<=a[3].x;++i){
			if(!vis[i][a[3].y]){
				vis[i][a[3].y]=1;
				++js;
			}
		}
	}
	printf("%d\n",js);
	for(int i=0;i<=1000;++i){
		for(int j=0;j<=1000;++j){
			if(vis[i][j]){
				printf("%d %d\n",i,j);
			}
		}
	}
	return 0;
}
/*

6 8
1 3 1 3
1 5 2 4
1 6 10 18
2 5 3 7
2 6 0 2
3 4 0 1
3 5 7 10
5 6 11 23





*/