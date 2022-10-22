#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> poly;
typedef pair<int,int> pii;
const int G=3;
const int Mod=998244353;
int n,m,nxt[110000]; bool flag[110000],vis[110000];
char s[110000],t[110000];
set<pii> st[25][110000];
pii add[25][110000],del[25][110000];
namespace polynomial{
	int rev[810000];
	inline ll add(ll x,ll y){ return x+y>=Mod?x+y-Mod:x+y;}
	inline ll dec(ll x,ll y){ return x-y<0?x-y+Mod:x-y;}
	ll qpow(ll x,ll a){
		ll res=1;
		while (a){
			if (a&1) res=res*x%Mod;
			x=x*x%Mod; a>>=1;
		}
		return res;
	}
	ll getinv(ll x){ return qpow(x,Mod-2);}
	void NTT(poly &a,int len,int inv){
		a.resize(len);
		for (int i=0;i<len;i++)
			if (i<rev[i]) swap(a[i],a[rev[i]]);
		for (int mid=1;mid<len;mid<<=1){
			ll tmp=qpow(G,(Mod-1)/(mid<<1));
			if (inv==-1) tmp=getinv(tmp);
			for (int i=0;i<len;i+=(mid<<1)){
				ll omega=1;
				for (int j=0;j<mid;j++,omega=omega*tmp%Mod){
					ll x=a[i+j],y=omega*a[i+j+mid]%Mod;
					a[i+j]=add(x,y); a[i+j+mid]=dec(x,y);
				}
			}
		}
		if (inv==-1){
			ll tmp=getinv(len);
			for (int i=0;i<len;i++) a[i]=a[i]*tmp%Mod;
		}
	}
	poly f,ff,fff,g,gg,h,res;
	void work(){
		f.resize(n+1); ff.resize(n+1); fff.resize(n+1);
		g.resize(m); gg.resize(m); h.resize(m);
		for (int i=1;i<=n;i++) f[i]=(s[i]=='?'?0:(s[i]-'a'+1)),ff[i]=f[i]*f[i]%Mod,fff[i]=ff[i]*f[i]%Mod;
		for (int i=0;i<m;i++) g[i]=t[m-i]-'a'+1,gg[i]=g[i]*g[i]%Mod,h[i]=1;
	
		int bit=0,len=1;
		while (len<=n+m) bit++,len<<=1;
		for (int i=0;i<len;i++) rev[i]=(rev[i>>1]>>1)|((i&1)<<(bit-1));
		NTT(fff,len,1); NTT(ff,len,1); NTT(f,len,1);
		NTT(gg,len,1); NTT(g,len,1); NTT(h,len,1);
		res.resize(len);
		for (int i=0;i<len;i++) res[i]=(fff[i]*h[i]+(Mod-ff[i])*g[i]+(Mod-ff[i])*g[i]+f[i]*gg[i])%Mod;
		NTT(res,len,-1);
		for (int i=m;i<=n;i++)
			if (res[i]==0) flag[i]=true;
	}
}
void getnxt(){
	nxt[1]=0; int k=0;
	for (int i=2;i<=m;i++){
		while (k&&t[k+1]!=t[i]) k=nxt[k];
		if (t[k+1]==t[i]) k++; nxt[i]=k;
	}
}
int tot,p[110000];
void getp(){
	int now=nxt[m];
	while (now) p[++tot]=m-now,now=nxt[now];
	p[tot+1]=m;
}
int cnt,L[110000],R[110000],D[110000];
void resp(){
	for (int i=1;i<=tot;i++){
		cnt++; L[cnt]=p[i]; D[cnt]=p[i+1]-p[i];
		int j=i;
		for (;j<=tot&&(p[j+1]-p[j])==(p[i+1]-p[i]);j++);
		R[cnt]=p[j]; i=j+1;
	}
}
pii f[110000],g[110000];
void update(int i){
	pii &res=f[i]; res=max(res,g[i-m]);
	for (int j=1;j<=cnt;j++)
		if (!st[j][i%D[j]].empty()) res=max(res,*st[j][i%D[j]].rbegin());
	res.first++;

	for (int j=1;j<=cnt;j++){
		int l=i+L[j],r=i+R[j];
		if (l<=n) add[j][l]=pii(res.first,i);
		if (r<=n) del[j][r]=pii(res.first,i);
	}
}
void solve(){
	for (int i=m;i<=n;i++){
		for (int j=1;j<=cnt;j++)
			if (add[j][i].second) st[j][i%D[j]].insert(add[j][i]);
		if (flag[i]) update(i);
		for (int j=1;j<=cnt;j++)
			if (del[j][i].second) st[j][i%D[j]].erase(st[j][i%D[j]].find(del[j][i]));
		g[i]=max(g[i-1],pii(f[i].first,i));
	}
}
int main(){
	scanf("%s%s",s+1,t+1);
	n=strlen(s+1); m=strlen(t+1);
	polynomial::work();
	getnxt(); getp(); resp();
	solve();
	printf("%d\n",g[n].first);
	/*
	int x=g[n].second;
	while (x) vis[x]=true,x=f[x].second;
	int lst=0x3f3f3f3f;
	for (int i=n;i>=1;i--){
		if (vis[i]) lst=i;
		if (s[i]=='?'){
			int pos=m-(lst-i);
			if (pos>0) s[i]=t[pos];
			else s[i]='a';
		} 
	}
	puts(s+1);
	*/
	return 0;
}