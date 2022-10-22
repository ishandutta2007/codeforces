//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxn=(1<<12)+5,maxq=(1<<16)+5,maxb=(1<<8)+5;
int n,q,B,cnt,lim;
int a[maxn],pos[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
int id[maxn],rid[maxn];
vec<vec<vec<int>>> f;
int m;
pii res[2200005];
int merge(int x,int y){
	if(!x)return y;
	res[++m]=pii(x,y);
	return ++cnt;
}
int buf[maxn];
int g[maxb][maxb];
void solve(int c,int l,int r){
	if(l==r){f[c][id[l]][id[l]]=pos[l];return ;}
	int mid=l+((r-l)>>1);
	solve(c,l,mid);solve(c,mid+1,r);
	int len=0;
	for(int i=l;i<=r;i++)buf[++len]=id[i];
	sort(buf+1,buf+len+1);
	for(int i=1;i<=len;i++){
		int x=buf[i],s1=-1,s2=-1,t1=-1,t2=-1;
		if(rid[x]<=mid)s1=t1=x;else s2=t2=x;
		for(int j=i+1;j<=len;j++){
			int y=buf[j];
			if(rid[y]<=mid){if(s1==-1)s1=t1=y;else t1=y;}
			else{if(s2==-1)s2=t2=y;else t2=y;}
			if(s1==-1)g[x][y]=f[c][s2][t2];
			else if(s2==-1)g[x][y]=f[c][s1][t1];
			else g[x][y]=merge(f[c][s1][t1],f[c][s2][t2]);
		}
	}
	for(int i=1;i<=len;i++)for(int j=i+1;j<=len;j++)f[c][buf[i]][buf[j]]=g[buf[i]][buf[j]];
	return ;
}
int st[maxn],ed[maxn],ans[maxq];
int main(){
	n=read();q=read();B=sqrt(q);lim=(n-1)/B+1;cnt=n;
	for(int i=1;i<=n;i++)a[i]=read(),pos[a[i]]=i;
	f.resize(lim+1);
	for(int i=1;i<=lim;i++){
		f[i].resize(B);
		for(int j=0;j<B;j++)f[i][j].resize(B);
		int l=(i-1)*B+1,r=min(i*B,n),tmp=0;
		for(int j=1;j<=n;j++)if(a[j]>=l&&a[j]<=r)rid[tmp]=a[j],id[a[j]]=tmp++;
		solve(i,l,r);
	}
	for(int i=1;i<=q;i++){
		int l,r;
		l=read();r=read();
		for(int j=1;j<=lim;j++)st[j]=ed[j]=-1;
		for(int j=l;j<=r;j++){
			int c=(a[j]-1)/B+1;
			if(st[c]==-1)st[c]=ed[c]=id[a[j]];else ed[c]=id[a[j]];
		}
		int x=0;
		for(int j=1;j<=lim;j++){
			if(st[j]==-1)continue;
			x=merge(x,f[j][st[j]][ed[j]]);
		}
		ans[i]=x;
	}
	printf("%d\n",m+n);
	for(int i=1;i<=m;i++)printf("%d %d\n",res[i].fi,res[i].se);
	for(int i=1;i<=q;i++)printf("%d ",ans[i]);
	puts("");
    return 0;
}