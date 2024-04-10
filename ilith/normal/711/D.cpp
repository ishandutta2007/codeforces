#include<bits/stdc++.h>
#define rgi register int
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
template <typename T,typename... Ts> inline void write(T A,Ts... As){write(A),putchar(' '),write(As...);}
const int N=200010,mod=1000000007;
int n,u;
vector<int>a[N];
int vis[N],p[N];
long long ans=1;
int seq[N],hd,cnt,fl;
inline void link(int x,int y){
	a[x].push_back(y);
}
void dfs(int x,int f){
	seq[++hd]=x,vis[x]=f;
	for(rgi i=0;i<a[x].size();++i){
		int to=a[x][i];
		if(!vis[to])dfs(to,f);
		else if(!fl&&vis[to]==f){
			int res=0;
			while(seq[hd-res++]!=to);
			(ans*=p[res]-2)%=mod,fl=1,cnt+=res;
		}
	}
	--hd;
}
int main(){
	read(n),p[0]=1;
	for(rgi i=1;i<=n;++i)read(u),link(i,u),p[i]=(p[i-1]<<1)%mod;
	for(rgi i=1;i<=n;++i)if(!vis[i])hd=fl=0,dfs(i,i);
	write(((p[n-cnt]*ans)%mod+mod)%mod);
	return 0;
}