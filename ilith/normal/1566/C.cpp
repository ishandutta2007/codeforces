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
const int N=100010;
int T,n,ans,a[N];
char s[N],t[N];
signed main(){
	read(T);
	while(T--){
		read(n),scanf("%s\n%s",s+1,t+1),ans=0;
		for(rgi i=1;i<=n;++i)if((a[i]=s[i]-'0'+t[i]-'0')==1)ans+=2;
		for(rgi i=1;i<=n;++i){
		    if(!a[i]){
		    	++ans;
				if(a[i+1]==2&&i!=n)++ans,++i;
			}
			else if(a[i]==2&&a[i+1]==0&&i!=n)ans+=2,++i;
		}
		cout<<ans<<endl;
	}
	return 0;
}