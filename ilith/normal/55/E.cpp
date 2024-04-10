#include<bits/stdc++.h>
#define rgi register int
#define pdd pair<double,double>
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
const int N=200010;
int n,q;
pdd mius(pdd x,pdd y){return pdd(x.fi-y.fi,x.se-y.se);}
double mult(pdd x,pdd y){return (x.fi*y.se-x.se*y.fi);}
pdd a[N],x;
ll ans;
int chkout(){
	for(rgi i=1;i<=n;++i){
        if(mult(mius(a[i],x),mius(a[i+1],x))>=0)return 1;
    }
    return 0;
}
signed main(){
	read(n);
	for(rgi i=1;i<=n;++i)cin>>a[i].fi>>a[i].se,a[i+n]=a[i];
	read(q);
	while(q--){
		cin>>x.fi>>x.se,ans=(n*(n-1ll)*(n-2ll))/6ll;
		if(chkout()){
			puts("0");
			continue;
		}
        ll j=1,num=0;
        for(rgi i=1;i<=n;++i){
            if(i!=1)--num;
            while(mult(mius(a[i],x),mius(a[j],x))<=0){
                if(j!=i)++num;
                j%=n,++j;
            }
            ans-=(num*(num-1ll)/2ll);
        }
        write(ans,'\n');
	}
	return 0;
}