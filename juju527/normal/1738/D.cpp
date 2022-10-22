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
const int maxn=1e5+5;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int b[maxn];
int len,p[maxn],rd[maxn];
vec e[maxn];
void dfs(int x){
	for(auto y:e[x])if(!rd[y])p[++len]=y;
	for(auto y:e[x])if(rd[y])p[++len]=y,dfs(y);
	return ;
}
int main(){
    int T;
	T=read();
	while(T--){
		int n,k;
		k=n=read();len=0;
		for(int i=1;i<=n;i++)b[i]=read();
		if(b[1]<1)k=0;
		for(int i=1;i<n;i++)if(b[i]>i&&b[i+1]<i+1)k=i;
		for(int i=1;i<=n;i++)e[i].clear(),rd[i]=0;
		for(int i=1;i<=n;i++)if(b[i]<=n&&b[i]>=1)e[b[i]].eb(i),rd[b[i]]++;
		for(int i=1;i<=n;i++){
			if(b[i]==n+1||b[i]==0){
				if(!rd[i])p[++len]=i;
			}
		}
		for(int i=1;i<=n;i++){
			if(b[i]==n+1||b[i]==0){
				if(rd[i])p[++len]=i,dfs(i);
			}
		}
		printf("%d\n",k);
		for(int i=1;i<=n;i++)printf("%d ",p[i]);
		puts("");
	}
    return 0;
}