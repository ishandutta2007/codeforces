#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define pii pair<int,int>
#define fi first
#define se second
#define fin(x) freopen(x,"r",stdin)
#define fout(x) freopen(x,"w",stdout)
typedef long long ll;
using namespace std;
inline void read(){}template <typename T,typename... Ts> inline void read(T& A,Ts&... As){
	T x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	A=x*f,read(As...);
}
inline void write(char a){putchar(a);}
template <typename T> inline void write(T a){
	if(a<0ll)putchar('-'),a=-a;
	if(a>9ll)write(a/10ll);
	putchar(a%10ll+'0');
}
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),write(As...);}
const ll N=1000010,mod=1e9+7;
inline ll qpow(ll a,ll b){
	ll ans=1;a%=mod;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1,a=a*a%mod;
	}
	return ans%mod;
}
ll t,n,m,p,a[N],f=1,ans;
map<int,int>mp;
map<int,int>::iterator it;
void chk(){
	while(!mp.empty()){
		it=--mp.end();
		if((*it).se!=0)break;
		else mp.erase(it);
	}
	if(mp.empty())f=1;
	else f=((*--mp.end()).se>0?-1:1);
}
signed main(){
	read(t);
	for(rgi W=1;W<=t;++W){
		read(n,p),ans=0,f=1;
		mp.clear();
		for(rgi i=1;i<=n;++i)read(a[i]);
		if(p==1){
			write(n&1,'\n');
			continue;
		}
		sort(a+1,a+n+1),reverse(a+1,a+n+1);
		for(rgi i=1;i<=n;++i){
			if(f==1){
				ans+=qpow(p,a[i]);
				++mp[a[i]];
				for(rgi g=a[i];;++g){
					if(mp[g]==p)mp[g]=0,++mp[g+1];
					else break;
				}
			}
			else{
				ans-=qpow(p,a[i]);
				--mp[a[i]];
				for(rgi g=a[i];;++g){
					if(mp[g]==-p)mp[g]=0,--mp[g+1];
					else break;
				}
			}
			chk();
		}
		write(((ans*-f)%mod+mod)%mod,'\n');
	}
	return 0;
}