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
	int ans=0;
	char ch=gc();
	while(!isdigit(ch))ch=gc();
	while(isdigit(ch))ans=((ans<<2)+ans<<1)+(ch^48),ch=gc();
	return ans;
}
typedef pair<int,int> pii;
const int N=2e5+5;
int n,a[N];
pii vl[N];
namespace small{
	inline void Main(){
		for(ri g1=0,g2=0,s=1,up=1<<n;s<up;++s,g1=0,g2=0){
			for(ri i=1;i<=n;++i)
			if((s>>(i-1))&1)g1=__gcd(a[i],g1);
			else g2=__gcd(a[i],g2);
			if(g1==1&&g2==1){
				puts("YES");
				for(ri j=1;j<=n;++j)cout<<(((s>>(j-1))&1)+1)<<' ';
				exit(0);
			}
		}
		puts("NO");
		exit(0);
	}
}
inline bool check(){return clock()*1000/CLOCKS_PER_SEC<=450;}
namespace big{
	int id[N],res[N];
	inline void Main(){
		srand(time(NULL));
		for(ri i=1;i<=n;++i)vl[i]=pii(a[i],i);
		int g,t,gg;
		while(check()){
			random_shuffle(vl+1,vl+n+1);
			g=gg=0;
			for(ri i=1;i<=n;++i)id[i]=0;
			for(ri i=1;i<=n;++i){
				t=__gcd(g,vl[i].fi);
				if(t^g)id[i]=1;
				else gg=__gcd(gg,vl[i].fi);
				g=t;
				if(g^1)continue;
				for(ri j=i+1;j<=n;++j)gg=__gcd(gg,vl[j].fi);
				if(gg==1){
					puts("YES");
					for(ri j=1;j<=n;++j)res[vl[j].se]=id[j]+1;
					for(ri j=1;j<=n;++j)cout<<res[j]<<' ';
					puts("");
					exit(0);
				}
				break;
			}
			
		}
		puts("NO");
		exit(0);
	}
}
int main(){
	n=read();
	int g=0;
	for(ri i=1;i<=n;++i)g=__gcd(g,a[i]=read());
	if(g^1)return puts("NO"),0;
	if(n<=20)small::Main();
	big::Main();
	return 0;
}