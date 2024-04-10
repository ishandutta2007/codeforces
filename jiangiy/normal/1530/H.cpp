#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=15005,M=600;
int n,s[N];
std::vector<std::pair<int,PI>>sl[N],sr[N];
struct data{
	int f[N];
	void init(){
		for(int i=1;i<=n;i++)f[i]=0;
	}
	void upd(int x,int y){
		for(;x<=n;x+=x&-x)f[x]=std::max(f[x],y);
	}
	int qry(int x){
		int r=0;
		for(;x;x&=x-1)r=std::max(r,f[x]);
		return r;
	}
}
fl[M],fr[M];
void setl(int u,int l,int r){
	fl[u].upd(n+1-l,n+1-r);
}
void setr(int u,int l,int r){
	fr[u].upd(r,l);
}
int qryl(int u,int l){
	int t=fl[u].qry(n+1-l);
	if(!t)return 0;
	return n+1-t;
}
int qryr(int u,int r){
	return fr[u].qry(r);
}
int work(bool tp){
	int lm=0,rm=0;
	for(int i=n;i;i--){
		assert(std::max(lm,rm)<M-10);
		for(int j=std::max(lm,rm);j;j--){
			int t=qryl(j,s[i]);
			if(t){
				setl(j+1,s[i],t);
				lm=std::max(lm,j+1);
				if(i>j)sr[i-j].push_back(MP(j+1,MP(s[i],t)));
			}
			t=qryr(j,s[i]);
			if(t){
				setr(j+1,t,s[i]);
				rm=std::max(rm,j+1);
				if(i>j)sl[i-j].push_back(MP(j+1,MP(t,s[i])));
			}
		}
		if(i==n){
			if(tp==0){
				setl(1,s[n],s[n]);
				setr(1,s[n],s[n]);
				if(!lm)lm=1;
				if(!rm)rm=1;
			}
		}
		else if(tp==1){
			setl(2,s[i],s[i]);
			setr(2,s[i],s[i]);
			if(!lm)lm=2;
			if(!rm)rm=2;
		}
		for(auto&x:sl[i]){
			setl(x.fi,x.se.fi,x.se.se);
			lm=std::max(lm,x.fi);
		}
		for(auto&x:sr[i]){
			setr(x.fi,x.se.fi,x.se.se);
			rm=std::max(rm,x.fi);
		}
	}
	for(int i=0;i<=std::max(lm,rm)+1;i++)fl[i].init();
	for(int i=0;i<=std::max(lm,rm)+1;i++)fr[i].init();
	for(int i=1;i<=n;i++)sl[i].clear();
	for(int i=1;i<=n;i++)sr[i].clear();
	return std::max(lm,rm)-(tp==1);
}
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",s+i);
	int a=work(0);
	int b=work(1);
	printf("%d\n",std::max(a,b));
}
int main(){
	int T;
	for(scanf("%d",&T);T--;solve());
}