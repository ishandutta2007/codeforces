#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx") 
#include<bits/stdc++.h>
using namespace std;

inline int read()
{
	int ret=0; char c=getchar();
	while(c<48||c>57)c=getchar();
	while(c>=48 && c<=57)ret=ret*10+c-48,c=getchar();
	return ret;
}
#define N 410040
struct node {
	int r,d;
};
vector<node>V[N];
int D,a[N],Ma,u,v,T,ma,h[N],l,r,o,mi,n,m,t,k,d;
inline int ch(int p)
{
	if(!p)return 1;
	D=a[p]+1;
	for(int i=1;i<=n;++i){
		h[i]=0;
		for(auto u:V[i]){
			if(u.d<D)continue;
			h[i]=max(h[i],u.r);
		}
	}
	T=(n+1)*3;ma=0;
	for(int i=1;i<=n+1;++i){
		ma=max(ma,h[i]);
		if(ma<i)T-=2;
	}
//	cerr<<p<<' '<<T<<endl;
	return T<=t;
}

int main()
{
	m=read();n=read();k=read();t=read();
	for(int i=1;i<=m;++i)a[i]=read();
	sort(a+1,a+m+1); reverse(a+1,a+m+1);
	for(int i=1;i<=k;++i){
		l=read();r=read();d=read();
		V[l].push_back((node){r,d});
	}
	l=0;r=m;
	while(l<=r){
		mi=l+r>>1;
		if(ch(mi))o=mi,l=mi+1;else r=mi-1;
	}
	cout<<o;
}