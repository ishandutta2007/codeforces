#include<bits/stdc++.h>
#define rgi register int
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
ll t,n;
ll d[N],a[N];
int main(){
	read(t);
	while(t--){
		read(n),n<<=1;
		for(rgi i=1;i<=n;++i)read(d[i]);
		sort(d+1,d+n+1);
		ll sum=0;
		for(rgi i=n;i>=1;i-=2){
			if((d[i]-sum)%i==0&&d[i]==d[i-1])a[i>>1]=(d[i]-sum)/i;
			else{puts("NO");goto tag;}
			sum+=a[i>>1]<<1;
		}
		sort(a+1,a+1+(n>>1));
		for(rgi i=n>>1;i>=1;--i){
			if(a[i]<=0||a[i]==a[i-1]){puts("NO");goto tag;}
		}
		puts("YES");
		tag:;
	}
	return 0;
}