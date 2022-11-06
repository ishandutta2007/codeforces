#include<bits/stdc++.h>
#define ri register int
#define pb push_back
using namespace std;
const int rlen=1<<18|1;
char buf[rlen],*ib=buf,*ob=buf;
#define gc() (((ib==ob)&&(ob=(ib=buf)+fread(buf,1,rlen,stdin)),ib==ob)?-1:*ib++)
inline int read(){
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef long long ll;
const int N=3e5+5;
struct F{
	int a,b,id;
	F(int a=0,int b=0,int id=0):a(a),b(b),id(id){}
	friend inline bool operator<(F a,F b){return a.a^b.a?a.a<b.a:(a.b^b.b?a.b<b.b:a.id<b.id);}
}a[N];
struct cmp{inline bool operator()(F a,F b){return a.b^b.b?a.b>b.b:(a.a^b.a?a.a>b.a:a.id<b.id);}};
set<F>smn,tp;
vector<F>res;
int n,vl[N];
int main(){
	#ifdef ldxcaicai
	freopen("lx.in","r",stdin);
	#endif
	n=read();
	ll s1=0,s2=0;
	for(ri i=1;i<=n;++i)a[i].a=read(),s1+=a[i].a,a[i].id=i;
	for(ri i=1;i<=n;++i)vl[i]=read(),s2+=vl[i];
	if(s1^s2)return puts("NO"),0;
	sort(a+1,a+n+1);
	sort(vl+1,vl+n+1);
	for(ri i=1;i<=n;++i)a[i].b=vl[i];
	for(ri i=1;i<=n;++i){
		if(a[i].a==a[i].b)continue;
		if(a[i].a<a[i].b)smn.insert(a[i]);
		else{
			while(smn.size()&&a[i].a>a[i].b){
				F t=*smn.begin();
				smn.erase(smn.begin());
				if(t.a<a[i].a-1){
					int d=min((a[i].a-t.a)/2,min(a[i].a-a[i].b,t.b-t.a));
					a[i].a-=d,t.a+=d;
					res.pb(F(t.id,a[i].id,d));
				}
				if(t.a!=t.b)tp.insert(t);
			}
			for(set<F>::iterator it=tp.begin();it!=tp.end();++it)smn.insert(*it);
			tp.clear();
			if(a[i].a!=a[i].b){
				puts("NO");
				return 0;
			}
		}
	}
	if(smn.size()){
		puts("NO");
		return 0;
	}
	puts("YES");
	cout<<res.size()<<'\n';
	for(ri i=0;i<res.size();++i)cout<<res[i].a<<' '<<res[i].b<<' '<<res[i].id<<'\n';
	return 0;
}