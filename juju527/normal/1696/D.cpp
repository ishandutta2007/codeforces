#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=2.5e5+5;
int n;
int a[maxn],p[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int pmx[maxn],pmn[maxn];
int smx[maxn],smn[maxn];
int solve1(int x,bool op){
	if(x==1)return 1;
	int y=p[op?pmn[x]:pmx[x]];
	return solve1(y,op^1)+1;
}
int solve2(int x,bool op){
	if(x==n)return 1;
	int y=p[op?smn[x]:smx[x]];
	return solve2(y,op^1)+1;
}
int main(){
    int T;
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=n;i++)a[i]=read(),p[a[i]]=i;
		pmx[0]=smx[n+1]=0;
		pmn[0]=smn[n+1]=n+1;
		for(int i=1;i<=n;i++)pmx[i]=max(pmx[i-1],a[i]),pmn[i]=min(pmn[i-1],a[i]);
		for(int i=n;i>=1;i--)smx[i]=max(smx[i+1],a[i]),smn[i]=min(smn[i+1],a[i]);
		int res=solve1(p[n],1)+solve2(p[n],1)-2;
		printf("%d\n",res);
	}
    return 0;
}