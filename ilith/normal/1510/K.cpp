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
int a[N],b[N];
void p1(){
	for(rgi i=1;i<=n;i+=2)swap(a[i],a[i+1]);
}
void p2(){
	for(rgi i=1;i<=n/2;++i)swap(a[i],a[i+n/2]);
}
int check(){
	int res=1;
	for(rgi i=1;i<=n;++i){
		if(a[i]!=i)res=0;
	}
	return res;
}
int res=998244353;
signed main(){
	read(n);
	n<<=1;
	for(rgi i=1;i<=n;++i)read(a[i]),b[i]=a[i];
	int ans=0;
	while(ans<=2500){
		if(check()){
			res=min(res,ans);
			break;
		}
		p1(),++ans;
		if(check()){
			res=min(res,ans);
			break;
		}
		p2(),++ans;
		if(check()){
			res=min(res,ans);
			break;
		}
	}
	for(rgi i=1;i<=n;++i)a[i]=b[i];
	ans=0;
	while(ans<=2500){
		if(check()){
			res=min(res,ans);
			break;
		}
		p2(),++ans;
		if(check()){
			res=min(res,ans);
			break;
		}
		p1(),++ans;
		if(check()){
			res=min(res,ans);
			break;
		}
	}
	write(res<998244353?res:-1);
	return 0;
}