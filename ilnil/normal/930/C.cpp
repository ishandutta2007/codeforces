#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define min(a,b)(a<b?a:b)
#define max(a,b)(a>b?a:b)
#define ll long long
using namespace std;
const int N=1e5+5;
int n,m,x,y,d[N],t[N*4],t2[N*4];
int fi(int v,int l,int r,int x){
	if(r<=x)return t[v];
	int m=l+r>>1;
	if(x<=m)return fi(v<<1,l,m,x);
	int b=fi(v<<1|1,m+1,r,x);
	return max(b,t[v<<1]);
}
int fi2(int v,int l,int r,int x){
	if(x<=l)return max(t2[v],t[v]);
	int m=l+r>>1;
	if(x>m)return fi2(v<<1|1,m+1,r,x);
	int b=fi2(v<<1,l,m,x);
	b=max(b,t2[v<<1|1]);
	return max(t[v<<1|1],b);
}
void ch(int v,int l,int r,int x,int y){
	t[v]=max(t[v],y);
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ch(v<<1,l,m,x,y);else ch(v<<1|1,m+1,r,x,y);
}
void ch2(int v,int l,int r,int x,int y){
	t2[v]=max(t2[v],y);
	if(l==r)return;
	int m=l+r>>1;
	if(x<=m)ch2(v<<1,l,m,x,y);else ch2(v<<1|1,m+1,r,x,y);
}
int main(){
//	freopen("a.in","r",stdin);
	scanf("%d%d",&n,&m);
	fo(i,1,n)scanf("%d%d",&x,&y),d[x]++,d[y+1]--;
	fo(i,1,m)d[i]+=d[i-1];
	fo(i,1,m){
		ch2(1,0,n,d[i],fi2(1,0,n,d[i])+1);
		ch(1,0,n,d[i],fi(1,0,n,d[i])+1);
	}
	printf("%d",max(t[1],t2[1]));
}