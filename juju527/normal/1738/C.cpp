//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
const int maxn=105;
bool f[maxn][maxn][2],g[maxn][maxn][2];
bool visf[maxn][maxn][2],visg[maxn][maxn][2];
bool dfs(int x,int y,bool op,bool typ){
	if(!x&&!y)return (op==0);
	if(typ==0){
		if(visf[x][y][op])return f[x][y][op];
		visf[x][y][op]=1;
		bool tag=0;
		if(x)tag|=dfs(x-1,y,op,1);
		if(y)tag|=dfs(x,y-1,op^1,1);
		return f[x][y][op]=tag;
	}
	else{
		if(visg[x][y][op])return g[x][y][op];
		visg[x][y][op]=1;
		bool tag=1;
		if(x)tag&=dfs(x-1,y,op,0);
		if(y)tag&=dfs(x,y-1,op,0);
		return g[x][y][op]=tag;
	}
}
int main(){
    int T;
	T=read();
	while(T--){
		int n,cnt0=0,cnt1=0;
		n=read();
		for(int i=1;i<=n;i++){
			int x=read();
			if(x%2!=0)cnt1++;else cnt0++;
		}
		if(dfs(cnt0,cnt1,0,0))puts("Alice");
		else puts("Bob");
	}
    return 0;
}