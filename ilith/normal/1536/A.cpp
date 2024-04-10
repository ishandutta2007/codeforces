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
ll t,n,a[N],z,f;
map<int,int> s;
int ans;
signed main(){
	read(t);
	while(t--){
		read(n),ans=0,s.clear();
		f=z=0;
		for(rgi i=1;i<=n;++i){
			read(a[i]);
			++s[a[i]];
			if(a[i]<0)f=1;
			if(a[i]>0)z=1;
		}
		if(f){
			puts("NO");
			continue;
		}
		puts("YES");
		write(101,'\n');
		for(rgi i=0;i<=100;++i){
			write(i, ' ');
		}
		puts("");
	}
	return 0;
}