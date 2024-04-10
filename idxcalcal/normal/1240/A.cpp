#include<bits/stdc++.h>
#define ri register int
#define pb push_back
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
typedef long long ll;
typedef pair<int,int> pii;
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
inline ll readl(){
	ll ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
inline int Read(bool*s){
	int top=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))s[++top]=ch^48,ch=gc();
	return top;
}
const int N=2e5+5;
int n,p[N],x,a,y,b,vl[N],mp[N];
ll k;
inline bool check(int mid){
	for(ri i=1;i<=mid;++i)mp[i]=vl[i];
	sort(mp+1,mp+mid+1);
	ll res=0;
	for(ri p1=n,p2=mid;p2;--p1,--p2){
		res+=(ll)p[p1]*mp[p2];
	}
	return res>=k;
}
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	for(ri tt=read();tt;--tt){
		n=read();
		for(ri i=1;i<=n;++i)p[i]=read()/100,vl[i]=0;
		sort(p+1,p+n+1);
		x=read(),a=read();
		y=read(),b=read();
		k=readl();
		for(ri i=a;i<=n;i+=a)vl[i]+=x;
		for(ri i=b;i<=n;i+=b)vl[i]+=y;
		priority_queue<int>q;
		for(ri i=1;i<=n;++i)q.push(p[i]*vl[i]);
		int l=1,r=n,res=n+1;
		while(l<=r){
			int mid=l+r>>1;
			if(check(mid))r=mid-1,res=mid;
			else l=mid+1;
		}
		cout<<(res==n+1?-1:res)<<'\n';
	}
	return 0;
}