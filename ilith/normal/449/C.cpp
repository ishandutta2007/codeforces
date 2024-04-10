#include<bits/stdc++.h>
#define rgi register int
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
const int N=100010;
int n;
int vis[N];
inline int isprime(int x){
	for(rgi i=2;i*i<=x;++i){
		if(x%i==0)return 0;
	}
	return 1;
}
signed main(){
	read(n);
	int ans=n-1;
	for(rgi i=n/2+1;i<=n;++i){
		if(isprime(i))--ans,vis[i]=1;
	}
	write(ans/2,'\n');
	for(rgi i=3;i<=n/2;i+=2){
		if(isprime(i)){
			int cnt=0;
			for(rgi j=1;i*j<=n;j+=2){
				if(!vis[i*j])++cnt;
			}
			if(cnt%2==0){
				int r=0;
				for(rgi j=1;i*j<=n;j+=2){
					if(vis[i*j])continue;
					if(r){
						write(i*j,' ',r,'\n');
						vis[i*j]=vis[r]=1;
						r=0;
					}
					else r=i*j;
				}
			}
			else{
				int r=0;
				for(rgi j=3;i*j<=n;j+=2){
					if(vis[i*j])continue;
					if(r){
						write(i*j,' ',r,'\n');
						vis[i*j]=vis[r]=1;
						r=0;
					}
					else r=i*j;
				}
				write(i,' ',i*2,'\n');
				vis[i*2]=vis[i]=1;
			}
		}
	}
	int r=0;
	for(rgi i=2;i<=n;i+=2){
		if(vis[i])continue;
		if(r){
			write(i,' ',r,'\n');
			r=0;
		}
		else r=i;
	}
	return 0;
}