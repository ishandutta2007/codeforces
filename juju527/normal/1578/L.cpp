#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int maxm=2e5+5,mod=998244353;
int read(){
    int x=0,y=1;
    char ch=getchar();
    while(ch<48||ch>57){if(ch==45)y=-1;ch=getchar();}
    while(ch>=48&&ch<=57)x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    return x*y;
}
struct node{int rd,ls,rs,laz,val,id;}t[maxm];
int tot,rt;
int newnode(int id){
	int k=++tot;
	t[k]=(node){rand(),0,0,0,0,id};
	return k;
}
void add_laz(int k,int v){if(k)t[k].laz+=v,t[k].val+=v;return ;}
void pushdown(int k){
	if(!t[k].laz)return ;
	add_laz(t[k].ls,t[k].laz),add_laz(t[k].rs,t[k].laz);
	t[k].laz=0;
	return ;
}
void split(int k,int &a,int &b,int s){
	if(!k){a=b=0;return ;}
	pushdown(k);
	if(t[k].val<=s)a=k,split(t[k].rs,t[a].rs,b,s);
	else b=k,split(t[k].ls,a,t[b].ls,s);
	return ;
}
void merge(int &k,int a,int b){
	if(a==0||b==0){k=a+b;return ;}
	pushdown(a),pushdown(b);
	if(t[a].rd<t[b].rd)k=a,merge(t[k].rs,t[a].rs,b);
	else k=b,merge(t[k].ls,a,t[b].ls);
	return ;
}
int len,p[maxm],q[maxm];
void dfs(int x){
	if(!x)return ;
	pushdown(x);
	dfs(t[x].ls);
	len++;p[len]=t[x].id;q[len]=t[x].val;
	dfs(t[x].rs);
	return ;
}
inline int add(int x){return x>=mod?x-mod:x;}
inline int sub(int x){return x<0?x+mod:x;}
inline int power(int x,int b){
	int res=1;
	while(b){
		if(b&1)res=1ll*res*x%mod;
		x=1ll*x*x%mod;
		b>>=1;
	}
	return res;
}
const int N=4e5;
int fc[N+5],ifc[N+5];
int binom(int n,int m){
	if(n<m||m<0)return 0;
	return 1ll*fc[n]*ifc[m]%mod*ifc[n-m]%mod;
}
int main(){
//    freopen("CF1558D.in","r",stdin);
//    freopen("CF1558D.out","w",stdout);
	srand(time(0));
    int T;
	T=read();
	fc[0]=1;for(int i=1;i<=N;i++)fc[i]=1ll*fc[i-1]*i%mod;
	ifc[N]=power(fc[N],mod-2);for(int i=N-1;i>=0;i--)ifc[i]=1ll*ifc[i+1]*(i+1)%mod;
	while(T--){
		int n,m;
		n=read();m=read();
		tot=rt=0;
		for(int i=1;i<=m;i++){
			int x,y;
			x=read();y=read();
			int a=0,b=0,u=newnode(x);
			t[u].val=y;
			split(rt,a,b,y-1);merge(a,a,u);
			add_laz(b,1);merge(rt,a,b);
		}
		len=0;
		dfs(rt);
		int k=1;
		for(int i=2;i<=m;i++){
			if(q[i-1]==q[i]-1){if(p[i]<p[i-1])k++;}
			else k++;
		}
		if(m>0&&q[m]<n)k++;
		printf("%d\n",binom(2*n-k,n-k));
	}
    return 0;
}