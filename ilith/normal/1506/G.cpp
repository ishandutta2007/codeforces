#include<bits/stdc++.h>
#define rgi register int
#define clear(x) memset(x,0,sizeof x)
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
const int N=200010,S=280;
int t,n;
char s[N],q[N],x;
int cnt[S],vis[S],hd;
signed main(){
	read(t);
	while(t--){
		scanf("%s",s),n=strlen(s),hd=0;
		clear(cnt),clear(vis);
		for(rgi i=0;i<n;++i)++cnt[s[i]];
		for(rgi i=0;i<n;++i){
			if(!vis[s[i]]){
				while(hd&&(x=q[hd])<=s[i]&&cnt[x])vis[x]=0,--hd;
				vis[q[++hd]=s[i]]=1;
			}
			--cnt[s[i]];
		}
		for(rgi i=1;i<=hd;++i)putchar(q[i]);
		puts("");
	}
	return 0;
}