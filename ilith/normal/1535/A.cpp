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
int t,a[N],b[N];
signed main(){
	read(t);
	while(t--){
		for(rgi i=1;i<=4;++i)read(a[i]),b[i]=a[i];
		sort(a+1,a+4+1);
		b[1]=max(b[1],b[2]),b[2]=max(b[3],b[4]);
		sort(b+1,b+2+1);
		if(b[1]==a[3]&&b[2]==a[4])puts("YES");
		else puts("NO");
	}
	return 0;
}