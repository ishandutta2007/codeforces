//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
typedef __int128 lll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector<int>
#define eb emplace_back
using namespace std;
const int maxn=3e4+5;
int p[maxn];
ll f[maxn][5];
ll read(){
    ll x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{int l,r;ll w;};
deque<node> g[5],h[5];
pii buf[5];
lll sum[5][5*maxn];
int l[5][maxn],r[5][maxn];
lll calc(int d,int l,int r){
	if(l>r)return 0;
	return sum[d][r]-((l==0)?0:sum[d][l-1]);
}
int main(){
	const int N=3e4;
	f[0][0]=1;
	for(int i=1;i<=N;i++){
		for(int j=0;j<=4;j++){
			f[i][j]=f[i-1][j];
			if(i>=2&&j>=1)f[i][j]+=f[i-2][j-1];
			if(i>=3&&j>=2)f[i][j]+=f[i-3][j-2];
			if(i>=4&&j>=3)f[i][j]+=f[i-4][j-3];
			if(i>=5&&j>=4)f[i][j]+=f[i-5][j-4];
		}
	}
	for(int i=0;i<=N;i++)for(int j=1;j<=4;j++)f[i][j]+=f[i][j-1];
    int T;
	T=read();
	while(T--){
		int n,c,q;
		n=read();c=read();q=read();
		for(int i=1;i<=n;i++)p[i]=read();
		for(int i=0;i<=c;i++)h[i].clear();
		for(int i=0;i<=c;i++)h[i].push_back((node){n+1,n+1,1});
		for(int i=n;i>=1;i--){
			int lim=min(c,n-i);
			for(int x=0;x<=lim;x++)buf[x]=pii(p[i+x],x);
			sort(buf,buf+lim+1);
			int pos=-1;
			for(int x=0;x<=lim;x++)if(buf[x].se==0)pos=x;
			for(int x=pos-1;x>=0;x--)
				for(int d=buf[x].se;d<=c;d++)
					h[d].push_front((node){i,i+buf[x].se,f[n-(i+buf[x].se)][d-buf[x].se]});
			for(int x=pos+1;x<=lim;x++)
				for(int d=buf[x].se;d<=c;d++)
					h[d].push_back((node){i,i+buf[x].se,f[n-(i+buf[x].se)][d-buf[x].se]});
		}
		for(int d=0;d<=c;d++){
			for(int i=1;i<=n;i++)l[d][i]=h[d].size(),r[d][i]=-1;
			int lst=-1;
			for(int i=0;i<h[d].size();i++){
				if(h[d][i].l>lst)l[d][h[d][i].l]=i;
				lst=h[d][i].l;
			}
			lst=-1;
			for(int i=h[d].size()-1;i>=0;i--){
				if(h[d][i].l>lst)r[d][h[d][i].l]=i;
				lst=h[d][i].l;
			}
			for(int i=n;i>=1;i--){
				l[d][i]=min(l[d][i],l[d][i+1]);
				r[d][i]=max(r[d][i],r[d][i+1]);
			}
			sum[d][0]=h[d][0].w;
			for(int i=1;i<h[d].size();i++)sum[d][i]=sum[d][i-1]+h[d][i].w;
		}
		while(q--){
			int pos;ll rk;
			pos=read();rk=read();
			if(f[n][c]<rk){puts("-1");continue;}
			int d=c,i=1,ans=0;
			while(1){
				int lt=l[d][i]-1,rt=r[d][i];
				while(lt+1<rt){
					int mid=lt+((rt-lt)>>1);
					if(calc(d,l[d][i],mid)>=rk)rt=mid;
					else lt=mid;
				}
				int x=h[d][rt].l,y=h[d][rt].r;
				if(pos<=y){
					if(pos<x)ans=p[pos];
					else ans=p[x+y-pos];
					break;
				}
				rk-=calc(d,l[d][i],lt);
				i=y+1;d-=y-x;
			}
			printf("%d\n",ans);
		}
	}
    return 0;
}