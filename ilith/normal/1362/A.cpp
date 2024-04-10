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
ll t,a,b,ans;
signed main(){
	read(t);
	while(t--){
		read(a,b),ans=0;
		if(a>b)swap(a,b);
		while(a<b){
			if(a*8<=b)a*=8,++ans;
			else if(a*4<=b)a*=4,++ans;
			else if(a*2<=b)a*=2,++ans;
			else if(a==b)break;
			else{
				ans=-1;
				break;
			}
		}
		write(ans,'\n');
	}
	return 0;
}