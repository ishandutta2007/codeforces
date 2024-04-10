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
using namespace std;

inline int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
inline void Out(LL x){
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

const LL P=1e9+7;
const int N=100005;
int n;
int ans[N];
vector<int> ve[N];
int main(){
    //freopen("1.in","r",stdin);
    //freopen("1.out","w",stdout);
    n=read();
    int x,js=0,y=0;
    for(int i=1;i<=n;++i){
    	x=read();
    	ve[x].push_back(i);
    	if(x>=n){
    		puts("Impossible");
			return 0;
		}
	}
	for(int i=0;i<n;++i){
		if(!ve[i].size()) continue;
		x=n-i;
		if(ve[i].size()%x!=0){
			puts("Impossible");
			return 0;
		}
		++js;
		y=0;
		for(int j=0;j<ve[i].size();++j){
			++y;
			if(y>x){
				y-=x;
				++js;
			}
			ans[ve[i][j]]=js;
		}
	}
	puts("Possible");
	for(int i=1;i<=n;++i) printf("%d ",ans[i]);
	puts("");
	return 0;
} 
/*
4 1
1 3 5 7

*/