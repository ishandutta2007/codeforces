#include <bits/stdc++.h>
#define ll long long
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxn=2e5+5;
int cnt[maxn][18];
int main(){
	int T;
	T=read();
	for(int i=1;i<=200000;i++)
		for(int j=0;j<18;j++)cnt[i][j]=cnt[i-1][j]+((i>>j)&1);
	while(T--){
		int l,r;
		l=read();r=read();
		int res=r;
		for(int i=0;i<18;i++)res=min(res,r-l+1-cnt[r][i]+cnt[l-1][i]);
		printf("%d\n",res);
	}
    return 0;
}