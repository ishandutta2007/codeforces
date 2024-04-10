#include<bits/stdc++.h>
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
using namespace std;
const int N=200005;
int n,s[N];
LL w(int x,int y,int t,bool v){
	return(v?(LL)s[x]*s[y]:0)+(LL)t*(s[x]+s[y]);
}
LL solve(int t,bool v){
	int u=-t;
	if(u<=s[1]){
		LL res=0;
		for(int i=2;i<=n;i++)res+=w(1,i,t,v);
		return res;
	}
	if(u>=s[n]){
		LL res=0;
		for(int i=1;i<=n-1;i++)res+=w(n,i,t,v);
		return res;
	}
	LL res=w(1,n,t,v);
	for(int i=2;i<=n-1;i++){
		if(s[i]>=u)res+=w(1,i,t,v);
		else res+=w(n,i,t,v);
	}
	return res;
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		sort(s+1,s+n+1);
		LL a=solve(1e6+1,0),b=solve(-1e6-1,0);
		if(a>0||b>0){
			puts("INF");
			continue;
		}
		LL l=s[1]-1,r=s[n]+1,mx=-1e18;
		auto get=[&](LL x){
			LL t=solve(x,1);
			mx=max(mx,t);
			return t;
		}
		;
		LL lv=get(l),rv=get(r);
		while(l+5<=r){
			LL ml=(l*2+r)/3,mr=(l+r*2)/3;
			LL mlv=get(ml),mrv=get(mr);
			if(mlv>mrv)r=mr,rv=mrv;
			else l=ml,lv=mlv;
		}
		for(int i=l+1;i<=r-1;i++)get(i);
		printf("%lld\n",mx);
	}
}