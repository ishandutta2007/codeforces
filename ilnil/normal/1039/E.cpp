#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define fo(i,a,b)for(int i=a,_e=b;i<=_e;i++)
#define gc()(it==iss?it=(iss=in)+fread(in,1,Q,stdin),(iss==it?EOF:*iss++):*iss++)
#define flush()fwrite(out,1,os-out,stdout),os=out
#define put(x)(*os++=x,os==ot?flush():0)
using namespace std;
const int N=1e5+5,S=40,M=17,Q=(1<<21)+1;
int n,w,q,z,a[N],k[N],k2[N],bi[N][S+1],sm[N][S+1],f[N][M],g[N][M],fw[N],gg[N];
struct tr;
tr *nu;
struct tr{
	tr *f,*s[2];
	int id,su;
	bool is,r;
	inline void now(){su=s[0]->su+s[1]->su+1;}
	inline void Cl(){
		if(is)f->Cl();
		if(r)r=0,swap(s[0],s[1]),s[0]->r^=1,s[1]->r^=1;
	}
	inline void ro(){
		tr *y=f;bool z=this==f->s[1];
		(y->s[z]=s[!z])->f=y;
		f=y->f;y->is?f->s[y==y->f->s[1]]=this:0;
		(s[!z]=y)->f=this;y->now();swap(is,y->is);
	}
	inline void sp(){
		for(Cl();is;ro())
			if(f->is)(this==f->s[1])==(f==f->f->s[1])?f->ro():ro();
		now();
	}
}t[N];
vector<int>v[N];
map<int,int>ans;
char o[20],c,in[Q],*iss=in,*it=in,out[Q],*os=out,*ot=out+Q-1;
inline void R(int &n){
	for(n=0;(c=gc())<'0'||c>'9';);
	for(;c<='9'&&c>='0';c=gc())n=n*10+(c&15);
}
inline void W(int n){
	if(!n)put('0');
	for(c=0;n;n/=10)o[++c]=n%10+48;
	for(;c;)put(o[c--]);put('\n');
}
inline void ac(tr* x){
	for(tr* y=nu;x!=nu;x->now(),y=x,x=x->f)
		x->sp(),x->s[1]->is=0,y->is=1,x->s[1]=y;
}
inline void mr(tr* x){
	ac(x);x->sp();x->r^=1;
}
inline int gr(tr* x){
	ac(x);x->sp();
	for(;x->s[0]!=nu;x=x->s[0]);
	return x->id;
}
inline void link(tr* x,tr* y){
	mr(x);x->f=y;
}
inline void cut(tr* x,tr* y){
	int o=gr(x);
	x->r^=1;ac(y);y->sp();
	x->is=0;x->f=y->s[0]=nu;y->now();
	mr(t+o);
}
inline int calc(int k){
	int tot=0,ma,mi;
	for(int i=1;i<=n;){
		ac(t+i);t[i].sp();tot+=t[i].su-1;i=gr(t+i);
		if(i>n)return tot;
		ma=0;mi=1e9;
		for(int j=gg[n+1-i];~j;j--)
			if(i+(1<<j)<=n+1&&max(ma,f[i][j])-min(mi,g[i][j])<=k)
				ma=max(ma,f[i][j]),mi=min(mi,g[i][j]),i+=1<<j;
		tot++;
	}
	return tot;
}
int main(){
	R(n);R(w);R(q);nu=t;
	fo(i,1,n)R(a[i]);
	fo(i,1,q)R(k[i]),k2[i]=k[i]=w-k[i];
	sort(k2+1,k2+q+1);
	fo(i,1,n){
		bi[i][0]=sm[i][0]=f[i][0]=g[i][0]=a[i];z=0;
		fo(j,1,min(S,n-i)){
			bi[i][j]=max(bi[i][j-1],a[i+j]);
			sm[i][j]=min(sm[i][j-1],a[i+j]);
			int wz=lower_bound(k2+1,k2+q+1,bi[i][j]-sm[i][j])-k2;
			if(wz>z)v[wz].push_back(i);
			z=wz;
		}
	}
	fo(j,1,M-1)fo(i,1,n-(1<<j)+1)
		f[i][j]=max(f[i][j-1],f[i+(1<<j-1)][j-1]),g[i][j]=min(g[i][j-1],g[i+(1<<j-1)][j-1]);
	fo(i,1,n+1)t[i].f=&t[i+1],t[i].s[0]=t[i].s[1]=nu,t[i].id=i;t[n+1].f=nu;
	fo(i,2,n)gg[i]=gg[i>>1]+1;
	fo(i,1,q){
		for(auto j:v[i]){
			cut(t+j,t+j+fw[j]+1);
			for(;fw[j]<S&&bi[j][fw[j]+1]-sm[j][fw[j]+1]<=k2[i];)fw[j]++;
			if(fw[j]<S)link(t+j,t+j+fw[j]+1);
		}
		ans[k2[i]]=calc(k2[i]);
	}
	fo(i,1,q)W(ans[k[i]]-1);flush();
}