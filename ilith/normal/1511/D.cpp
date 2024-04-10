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
const int N=300010;
int n,k;
void solve(char a){
	if(!n||a-'a'>=k)return;
	putchar(a),--n;if(!n)return;
	solve(a+1);
	for(rgi i=a-'a'+2;i<k&&n;++i){
		if(!n)return;
		putchar(a),--n;if(!n)return;
		putchar(i+'a'),--n;
	}
	if(!n)return;
	putchar(a),--n;
	if(!n||a-'a'==k-1)return;
	if(a!='a')putchar(a),--n;
}
signed main(){
	read(n,k);
	while(n)solve('a');
	return 0;
}