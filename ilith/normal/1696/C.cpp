#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,b,a) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int N=1e5+7;
int T,n,m,k,a[N],b[N];
ll su;
struct node{
	ll v,ct;
	ll val(){return v*ct;}
	bool operator==(node x)const{return v==x.v&&ct==x.ct;}
}p[N],q[N];
vector<node>x,y;
void solve(){
	scanf("%d%d",&n,&m),su=0;
	x.clear(),y.clear();
	FOR(i,1,n){
		scanf("%d",a+i),su+=a[i];
		int cnt=1;
		while(a[i]%m==0)a[i]/=m,cnt*=m;
		p[i]={a[i],cnt};
	}
	int ls=1;
	FOR(i,2,n){
		if(a[i]!=a[ls])ls=i;
		else p[ls].ct+=p[i].ct,p[i].ct=0;
	}
	scanf("%d",&k);
	FOR(i,1,k){
		scanf("%d",b+i),su-=b[i];
		int cnt=1;
		while(b[i]%m==0)b[i]/=m,cnt*=m;
		q[i]={b[i],cnt};
	}
	if(su){puts("No");return;}
	ls=1;
	FOR(i,2,k){
		if(b[i]!=b[ls])ls=i;
		else q[ls].ct+=q[i].ct,q[i].ct=0;
	}
	FOR(i,1,k)if(q[i].ct)y.emplace_back(q[i]);
	FOR(i,1,n)if(p[i].ct)x.emplace_back(p[i]);
	puts(x==y?"Yes":"No");
}
int main(){
	for(scanf("%d",&T);T--;)solve();
	return 0;
}