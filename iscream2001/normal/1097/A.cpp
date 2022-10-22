#pragma GCC optimize("-O2")
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<bitset>
#include<ctime>
#include<cstdlib> 
#define LL long long
#define DB double
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

char ch[5];
char s[5];
int a[10000];

int main(){
//    freopen("1.in","r",stdin);
//    freopen("1.out","w",stdout);
	scanf("%s",ch+1);
	for(int i=1;i<=5;++i){
		scanf("%s",s+1);
		++a[s[1]];
		++a[s[2]];
	}
	if(a[ch[1]]||a[ch[2]]) puts("YES");
	else puts("NO");
	return 0;
}
/*
1
0
*/