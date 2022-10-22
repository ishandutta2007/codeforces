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
const int N=200010;
int t,n;
ll s[N],u[N],ans[N],sum[N];
vector<ll>a[N];
signed main(){
	read(t);
	while(t--){
		read(n),memset(ans,0,sizeof ans);memset(sum,0,sizeof sum);
		for(rgi i=1;i<=n;++i){
			read(u[i]);
		}
		for(rgi i=1;i<=n;++i){
			read(s[i]),sum[u[i]]+=s[i];
			a[u[i]].push_back(s[i]);
		}
		for(rgi i=1;i<=n;++i){
			if(a[i].size()){
				sort(a[i].begin(),a[i].end());
				for(rgi j=1;j<a[i].size();++j)a[i][j]+=a[i][j-1];
				for(rgi j=1;j<=a[i].size();++j){
					if(a[i].size()%j)ans[j]+=sum[i]-a[i][a[i].size()%j-1];
					else ans[j]+=sum[i];
				}
			}
		}
		for(rgi i=1;i<=n;++i){
			write(ans[i],' ');
			a[i].clear();
		}
		puts("");
	}
	return 0;
}