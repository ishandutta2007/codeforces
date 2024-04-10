#include<bits/stdc++.h>
#define mod 20190816170251
typedef long long ll;
ll gi(){
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch))f^=ch=='-',ch=getchar();
	while(isdigit(ch))x=x*10+ch-'0',ch=getchar();
	return f?x:-x;
}
std::mt19937 rnd(time(NULL));
#define rand rnd
#define pr std::pair<int,int>
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second
template<class T>void cxk(T&a,T b){a=a>b?a:b;}
template<class T>void cnk(T&a,T b){a=a<b?a:b;}
#ifdef mod
int pow(int x,int y){
	int ret=1;
	while(y){
		if(y&1)ret=1ll*ret*x%mod;
		x=1ll*x*x%mod;y>>=1;
	}
	return ret;
}
template<class Ta,class Tb>void inc(Ta&a,Tb b){a=a+b>=mod?a+b-mod:a+b;}
template<class Ta,class Tb>void dec(Ta&a,Tb b){a=a>=b?a-b:a+mod-b;}
#endif
std::unordered_map<ll,int>M;
int n,S,D,L,R,_n;
struct bits{
	std::vector<unsigned short>v;
	bits(){v.resize(_n);}
	void set(int x){v[x/16]|=1<<x%16;}
}C[33];
bits operator^(bits a,const bits&b){
	for(int i=0;i<_n;++i)a.v[i]^=b.v[i];
	return a;
}
void DFS(int x,int cnt,bits bit){
	if(x>S){
		ll Hash=0;
		for(int i=0;i<_n;++i)Hash=32768*(Hash+bit.v[i])%mod;
		if(!M.count(Hash))M[Hash]=1e9;
		cnk(M[Hash],cnt);return;
	}
	DFS(x+1,cnt,bit);
	DFS(x+1,cnt+1,bit^C[x]);
}
int ans=1e9;
void DFS2(int x,int cnt,bits bit){
	if(cnt>=ans)return;
	if(x>L){
		ll Hash=0;
		for(int i=0;i<_n;++i)Hash=32768*(Hash+bit.v[i])%mod;
		if(M.count(Hash))cnk(ans,cnt+M[Hash]);
		return;
	}
	DFS2(x+1,cnt,bit);
	DFS2(x+1,cnt+1,bit^C[x]);
}
int main(){
#ifdef LOCAL
	freopen("in.in","r",stdin);
	//freopen("out.out","w",stdout);
#endif
	n=gi(),S=gi(),D=gi(),R=std::min(20,S),L=S-R;
	_n=(n+15)/16;
	for(int i=1;i<=S;++i){
		C[i]={};
		int c=gi();
		while(c--)C[i].set(gi());
	}
	DFS(L+1,0,bits());
	while(D--){
		int c=gi();
		bits Q;
		while(c--)Q.set(gi());
		ans=1e9;
		DFS2(1,0,Q);
		if(ans==1e9)ans=-1;
		printf("%d\n",ans);
	}
	return 0;
}