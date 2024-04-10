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
int t,n;
char a[N];
signed main(){
	read(t);
	while(t--){
		scanf("%s",a+1),n=strlen(a+1);
		int fl=0,f0=0,l0=0;
		for(rgi i=1;i<=n;++i)if(a[i]=='0'){
			fl=1,l0=i;
			if(!f0)f0=i;
		}
		if(!fl){
			puts("0");
			continue;
		}
		fl=0;
		for(rgi i=f0+1;i<l0;++i){
			if(a[i]=='1')fl=1;
		}
		puts(fl?"2":"1");
	}
	return 0;
}