#include<bits/stdc++.h>
#define ri register int
#define fi first
#define se second
using namespace std;
const int rlen=1<<18|1;
inline char gc(){
	static char buf[rlen],*ib,*ob;
	(ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin));
	return ib==ob?-1:*ib++;
}
inline int read(){
	#define gc getchar
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
const int N=2e5+5;
struct SAM{
	int tim[N],add[N<<1],pos[N<<1],len[N<<1],lk[N<<1],son[N<<1][26],tot,last,cnt[N<<1],rk[N<<1];
	SAM(){tot=last=1;}
	inline void extend(int x,int id){
		int np=++tot,p=last;
		len[last=np]=len[p]+1,pos[np]=id;
		while(p&&!son[p][x])son[p][x]=np,p=lk[p];
		if(!p){lk[np]=1;return;}
		int q=son[p][x],nq;
		if(len[q]==len[p]+1){lk[np]=q;return;}
		len[nq=++tot]=len[p]+1,memcpy(son[nq],son[q],sizeof(son[nq])),lk[nq]=lk[q],lk[q]=lk[np]=nq;
		while(p&&son[p][x]==q)son[p][x]=nq,p=lk[p];
	}
	inline void build(char*s,int n){for(ri i=1;i<=n;++i)extend(s[i]-'a',i);}
	inline void topsort(){
		for(ri i=1;i<=tot;++i)++cnt[len[i]];
		for(ri i=1;i<=tot;++i)cnt[i]+=cnt[i-1];
		for(ri i=tot;i;--i)rk[cnt[len[i]]--]=i;
		for(ri i=1;i<=tot;++i){
			add[rk[i]]+=add[lk[rk[i]]];
			tim[pos[rk[i]]]=add[rk[i]];
		}
		tim[0]=0;
	}
	inline void update(char*s,int n){
		int p=1;
		for(ri i=1;i<=n;++i){
			p=son[p][s[i]-'a'];
			if(!p)return;
		}
		++add[p];
	}
}pre,suf;
int n,lim;
char s[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	scanf("%s",s+1),lim=n=strlen(s+1);
	pre.build(s,n);
	reverse(s+1,s+n+1);
	suf.build(s,n);
	for(ri tt=read();tt;--tt){
		scanf("%s",s+1),n=strlen(s+1);
		pre.update(s,n);
		reverse(s+1,s+n+1);
		suf.update(s,n);
	}
	pre.topsort(),suf.topsort();
	ll ans=0;
	for(ri i=1;i<=lim;++i)ans+=(ll)pre.tim[i]*suf.tim[lim-i];
	cout<<ans;
	return 0;
}