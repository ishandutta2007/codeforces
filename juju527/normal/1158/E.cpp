//Code by juju527.
#include<bits/stdc++.h>
typedef long long ll;
#define pii pair<int,int>
#define fi first
#define se second
#define vec vector
#define eb emplace_back
using namespace std;
const int maxn=1005;
int n;
int d[maxn],a[maxn];
char s[maxn];
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
void query(){
	printf("?");
	for(int i=1;i<=n;i++)printf(" %d",d[i]);
	puts("");fflush(stdout);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)a[i]=s[i]-'0';
	return ;
}
vec<pii> p[11];
map<pii,int> mp;
void solve(int l,int r,int d){
	if(l>=r)return ;
	mp[pii(l,r)]=p[d].size();
	p[d].eb(pii(l,r));
	int mid=l+((r-l)>>1);
	solve(l,mid-1,d+1);solve(mid+1,r,d+1);
	return ;
}
int buf[maxn];
vec<int> dep[maxn];
pii f[maxn];
vec<int> aux[maxn];
int fa[maxn];
int main(){
	n=read();
	solve(1,n-1,0);dep[0].eb(1);f[1]=pii(0,0);
	for(int i=2;i<=n;i++){f[i]=pii(1,n-1);if(n==2)dep[1].eb(i);}
	for(int i=0;i<11;i++){
		if(!p[i].size())break;
		for(int x=1;x<=n;x++)d[x]=0;
		for(int j=0;j<p[i].size();j+=2){
			int l=p[i][j].fi,r=p[i][j].se,mid=l+((r-l)>>1);
			for(auto x:dep[l-1])d[x]=mid-l+1;
		}
		query();for(int i=1;i<=n;i++)buf[i]=a[i];
		for(int x=1;x<=n;x++)d[x]=0;
		for(int j=0;j<p[i].size();j+=2){
			int l=p[i][j].fi,r=p[i][j].se,mid=l+((r-l)>>1);
			for(auto x:dep[l-1])d[x]=mid-l;
		}
		query();
		for(int j=0;j<n;j++)aux[j].clear();
		for(int x=1;x<=n;x++)if(f[x].fi!=f[x].se)aux[mp[f[x]]].eb(x);
		for(int j=0;j<p[i].size();j+=2){
			int l=p[i][j].fi,r=p[i][j].se,mid=l+((r-l)>>1);
			for(auto x:aux[j]){
				if(f[x].fi!=l||f[x].se!=r)continue;
				if(buf[x]&&a[x]){f[x]=pii(l,mid-1);if(l==mid-1)dep[l].eb(x);}
				else if(buf[x]&&!a[x])f[x]=pii(mid,mid),dep[mid].eb(x);
				else{f[x]=pii(mid+1,r);if(r==mid+1)dep[r].eb(x);}
			}
		}
		for(int x=1;x<=n;x++)d[x]=0;
		for(int j=1;j<p[i].size();j+=2){
			int l=p[i][j].fi,r=p[i][j].se,mid=l+((r-l)>>1);
			for(auto x:dep[l-1])d[x]=mid-l+1;
		}
		query();for(int i=1;i<=n;i++)buf[i]=a[i];
		for(int x=1;x<=n;x++)d[x]=0;
		for(int j=1;j<p[i].size();j+=2){
			int l=p[i][j].fi,r=p[i][j].se,mid=l+((r-l)>>1);
			for(auto x:dep[l-1])d[x]=mid-l;
		}
		query();
		for(int j=0;j<n;j++)aux[j].clear();
		for(int x=1;x<=n;x++)if(f[x].fi!=f[x].se)aux[mp[f[x]]].eb(x);
		for(int j=1;j<p[i].size();j+=2){
			int l=p[i][j].fi,r=p[i][j].se,mid=l+((r-l)>>1);
			for(auto x:aux[j]){
				if(f[x].fi!=l||f[x].se!=r)continue;
				if(buf[x]&&a[x]){f[x]=pii(l,mid-1);if(l==mid-1)dep[l].eb(x);}
				else if(buf[x]&&!a[x])f[x]=pii(mid,mid),dep[mid].eb(x);
				else{f[x]=pii(mid+1,r);if(r==mid+1)dep[r].eb(x);}
			}
		}
	}
	for(int c=0;c<11;c++){
		if((1<<c)>n)break;
		for(int i=1;i<=n;i++)d[i]=0;
		for(int i=0;i<n;i+=3)for(auto x:dep[i])if((x>>c)&1)d[x]=1;
		query();
		for(int i=1;i<n;i+=3)for(auto x:dep[i])if(a[x])fa[x]|=(1<<c);
		for(int i=1;i<=n;i++)d[i]=0;
		for(int i=1;i<n;i+=3)for(auto x:dep[i])if((x>>c)&1)d[x]=1;
		query();
		for(int i=2;i<n;i+=3)for(auto x:dep[i])if(a[x])fa[x]|=(1<<c);
		for(int i=1;i<=n;i++)d[i]=0;
		for(int i=2;i<n;i+=3)for(auto x:dep[i])if((x>>c)&1)d[x]=1;
		query();
		for(int i=0;i<n;i+=3)for(auto x:dep[i])if(a[x])fa[x]|=(1<<c);
	}
	puts("!"),fflush(stdout);
	for(int i=2;i<=n;i++)printf("%d %d\n",i,fa[i]),fflush(stdout);
    return 0;
}