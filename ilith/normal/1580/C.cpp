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
const int N=200010,B=450;
int n,m,x[N],y[N],t[N],c[B+1][B+1];
int s[N],cb[N],ans;
void upd(int x,int v){
	s[x]+=v,cb[x/B]+=v;
}
int qry(int x){
	int res=0;
	for(rgi i=0;;i+=B){
		if(i+B>x){
			for(rgi j=i;j<=x;++j)res+=s[j];
			return res;
		}
		res+=cb[i/B];
	}
	return res;
}
signed main(){
	read(n,m);
	for(rgi i=1;i<=n;++i)read(x[i],y[i]); 
	for(int i=1;i<=m;i++){
		int o,k,v;
		read(o,k),v=(o==1?1:-1);
		if(o==1)t[k]=i;
		if(x[k]+y[k]<=B){
			for(rgi j=t[k]+x[k];j<t[k]+x[k]+y[k];++j)c[x[k]+y[k]][j%(x[k]+y[k])]+=v;
		}
		else{
			for(rgi j=0;t[k]+(x[k]+y[k])*j+x[k]<=m;++j){
				upd(t[k]+(x[k]+y[k])*j+x[k],v);
				if(t[k]+(x[k]+y[k])*(j+1)<=m)upd(t[k]+(x[k]+y[k])*(j+1),-v);
			}
		}
		ans=qry(i);
		for(rgi j=1;j<=B;++j)ans+=c[j][i%j];
		write(ans,'\n');
	}
	return 0;
}