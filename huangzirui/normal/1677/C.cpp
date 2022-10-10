#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline int read(){
	char c=getchar();int x=0,f=1;
    while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f;
}
const int maxn=100010;
int i,j,k,n,m,T,a[maxn],b[maxn],u[maxn],cnt,is[maxn],s;
void dfs(int now){
	if(!is[now]){
		if(s&1)++cnt;
		s=0;return;
	}
	is[now]=0;++s;
	dfs(u[b[now]]);
}
int main(){
	cin>>T;
	while(T--){
		cnt=0;
		cin>>n;
		for(i=1;i<=n;i++)is[i]=1;
		for(i=1;i<=n;i++)a[i]=read(),u[a[i]]=i;
		for(i=1;i<=n;i++)b[i]=read();
		for(i=1;i<=n;i++)if(is[i])dfs(i);
		cnt=n-cnt;
		ll ans=0;
		for(i=1;i<=n;i++)
			if(i<=cnt/2)ans+=(n-i-i+1)*2;
		printf("%lld\n",ans);
	}
	return 0;
}