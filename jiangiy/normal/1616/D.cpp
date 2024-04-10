#include<bits/stdc++.h>
#define fi first
#define se second
#define LL long long
#define PI std::pair<int,int>
#define MP std::make_pair
const int N=50005;
int n,x,s[N],st[N],sr[N],l[N],g[N],f[N],h[N];
LL p[N];
int ff(int x){
	return x+1;
}
int main(){
	int T;
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d",s+i);
		scanf("%d",&x);
		for(int i=1;i<=n;i++)s[i]-=x;
		for(int i=1;i<=n;i++)p[i]=p[i-1]+s[i];
		int c=2;
		st[c]=sr[c]=0;
		st[1]=n+1,sr[1]=-1;
		p[n+1]=1e18;
		for(int i=1;i<=n;i++){
			if(i<n&&s[i+1]<0){
				for(;c&&p[i+1]>=p[st[c]];c--);
				l[i+1]=!c?0:ff(sr[c]);
			}
			for(;c&&p[i]>p[st[c]];c--);
			if(i==1||s[i]>=0){
				l[i]=!c?0:ff(p[i]==p[st[c]]?sr[c-1]:sr[c]);
			}
			if(!c||p[i]!=p[st[c]])st[++c]=i,sr[c]=i;
			else sr[c]=i;
		}
		l[1]=0;
		c=0;
		int j=0,ans=0;
		for(int i=1;i<=n;i++){
			g[i]=std::max(g[i-1],l[i]);
			if(!g[i])f[i]=i;
			else f[i]=h[g[i]-1]+i-g[i];
			for(;j<c&&st[j]<g[i];j++);
			if(j!=c&&st[j]!=i-1)f[i]=std::max(f[i],f[st[j]]+i-st[j]-1);
			h[i]=std::max(h[i-1],f[i]);
			ans=std::max(ans,f[i]);
			for(;j<c&&f[st[c-1]]-st[c-1]<=f[i]-i;c--);
			st[c++]=i;
		}
		printf("%d\n",ans);
	}
}