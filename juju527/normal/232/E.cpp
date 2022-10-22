#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn=505,maxq=6e5+5;
int n,m,Q;
char s[maxn];
bool ban[maxn][maxn];
int q[maxq][4];
bool res[maxq];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
vector<int> que[maxn<<2];
void modify(int k,int l,int r,int id){
	if(l==r){que[k].push_back(id);return ;}
	int mid=l+((r-l)>>1);
	if(q[id][0]<=mid&&q[id][2]>mid){que[k].push_back(id);return ;}
	if(q[id][0]<=mid)modify(k<<1,l,mid,id);
	else modify(k<<1|1,mid+1,r,id);
	return ;
}
bitset<maxn> f[maxn][maxn],g[maxn][maxn];
void calc(int k,int l,int r){
	int mid=l+((r-l)>>1);
	for(int i=l;i<=r;i++)for(int j=1;j<=m;j++)f[i][j].reset(),g[i][j].reset();
	for(int j=1;j<=m;j++)if(!ban[mid][j])f[mid][j][j]=1,g[mid][j][j]=1;
	for(int i=r;i>=l;i--){
		for(int j=m;j>=1;j--){
			if(ban[i][j])continue;
			if(i<r)f[i][j]|=f[i+1][j];
			if(j<m)f[i][j]|=f[i][j+1];
		}
	}
	for(int i=l;i<=r;i++){
		for(int j=1;j<=m;j++){
			if(ban[i][j])continue;
			if(i>l)g[i][j]|=g[i-1][j];
			if(j>1)g[i][j]|=g[i][j-1];
		}
	}
	for(int i=0;i<que[k].size();i++){
		int id=que[k][i];
		res[id]=(f[q[id][0]][q[id][1]]&g[q[id][2]][q[id][3]]).any();
	}
	return ;
}
void solve(int k,int l,int r){
	calc(k,l,r);
	if(l==r)return ;
	int mid=l+((r-l)>>1);
	solve(k<<1,l,mid),solve(k<<1|1,mid+1,r);
	return ;
}
int main(){
//    freopen("CF232E.in","r",stdin);
//    freopen("CF232E.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		for(int j=1;j<=m;j++)ban[i][j]=(s[j]=='#');
	}
	Q=read();
	for(int i=1;i<=Q;i++){
		int x1,y1,x2,y2;
		x1=read();y1=read();x2=read();y2=read();
		if(x1>x2||y1>y2)continue;
		q[i][0]=x1,q[i][1]=y1,q[i][2]=x2,q[i][3]=y2;
		modify(1,1,n,i);
	}
	solve(1,1,n);
	for(int i=1;i<=Q;i++)res[i]?puts("Yes"):puts("No");
	return 0;
}