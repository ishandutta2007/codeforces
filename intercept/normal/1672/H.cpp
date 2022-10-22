#include<bits/stdc++.h>
#define ll long long 
#define eb emplace_back
#define fi first
#define se second
#define pii pair<int,int>
using namespace std;
const int mod=998244353;
int kpow(int x,int y,int rex=1){
    for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*x*rex%mod;
    return rex;
}
int exgcd(int a,int b,int &x,int &y){
    int t=b?exgcd(b,a%b,y,x):a;
    if(!b)x=1,y=0;
    else y-=a/b*x;
    return t;
}
const int M=2e5+9;
int n,m;
int c[2][M],bit[2][M],ans[M];
char s[M];
vector<pii>g[M];
void add(int *b,int i,int p){
	for(;i;i-=i&-i)b[i]+=p;
}
int ask(int *b,int i,int rex=0){
	for(;i<=n;i+=i&-i)rex+=b[i];
	return rex;
}
int main(){
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=m;++i){
		int l,r;
		scanf("%d%d",&l,&r);
		g[r].emplace_back(l,i);
	}
	for(int i=1;i<=n;++i){
		c[0][i]=c[0][i-1]+(s[i]=='0');
		c[1][i]=c[1][i-1]+(s[i]=='1');
	}
	for(int i=1;i<=n;++i){
		if(s[i]=='0'){
			if(s[i-1]!='0'){
				add(bit[0],i,1);
			}
			else add(bit[0],i,1),add(bit[0],i-1,-1);
		}
		if(s[i]=='1'){
			if(s[i-1]!='1'){
				add(bit[1],i,1);
			}
			else add(bit[1],i,1),add(bit[1],i-1,-1);
		}
		for(auto o:g[i]){
			ans[o.se]=max(c[0][i]-c[0][o.fi-1]-ask(bit[0],o.fi),c[1][i]-c[1][o.fi-1]-ask(bit[1],o.fi));
		}
	}
	for(int i=1;i<=m;++i)printf("%d\n",ans[i]+1);
	return 0;
}
/*
5 1
11011
2 4

*/