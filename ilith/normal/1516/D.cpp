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
const int N=100010,LOG=20;
int q,n,a[N],nxt[N][LOG],sum;
vector<int>s[N]; 
signed main(){
	read(n,q);
	for(rgi i=1;i<=n;++i){
		read(a[i]);
		nxt[i][0]=n+1;
		for(rgi j=1;j*j<=a[i];++j){
			if(a[i]%j==0){if(j!=1){
					s[j].push_back(i);
					if(s[j].size()>1)nxt[s[j][s[j].size()-2]][0]=min(nxt[s[j][s[j].size()-2]][0],i);
				}
				if(j*j!=a[i]){
					s[a[i]/j].push_back(i);
					if(s[a[i]/j].size()>1)nxt[s[a[i]/j][s[a[i]/j].size()-2]][0]=min(nxt[s[a[i]/j][s[a[i]/j].size()-2]][0],i);
				}
			}
		}
	}
	for(rgi i=1;i<=n;++i)--nxt[i][0];
	for(rgi i=n-1;i>=1;--i){
		nxt[i][0]=min(nxt[i][0],nxt[i+1][0]);
	}
	for(rgi w=1;w<LOG;++w){
		for(rgi i=1;i<=n;++i)if(nxt[i][w-1])nxt[i][w]=nxt[nxt[i][w-1]+1][w-1];
	}
	while(q--){
		int l,r,ans=0;
		read(l,r);
		for(rgi w=LOG-1;~w;--w){
			if(nxt[l][w]&&nxt[l][w]<=r){
				ans+=(1<<w),l=nxt[l][w]+1;
			}
		}
		write(ans+(l<=r),'\n');
	}
	return 0;
}