#include<bits/stdc++.h>
using namespace std;
#define ll long long
namespace io{
	const int l=1<<20;
	char buf[l],*s,*t;
	inline char gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,l,stdin);
			return s==t?EOF:*s++;
		}
		return *s++;
	}
	char c;
	template<class IT>inline void gi(IT &x){
		x=0;c=gc();while(c<'0'||c>'9')c=gc();
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
	}
};
using io::gi;
template<class IT>inline void _int(      IT &a,      IT &b  ){if(a>b)swap(a,b);}
template<class IT>inline void cmin(      IT &a,const IT &b=0){if(a>b)a=b;}
template<class IT>inline void cmax(      IT &a,const IT &b=0){if(a<b)a=b;}
template<class IT>inline IT   _min(const IT &a,const IT &b=0){return a>b? b:a;}
template<class IT>inline IT   _max(const IT &a,const IT &b=0){return a<b? b:a;}
template<class IT>inline IT   _abs(const IT &a              ){return a<0?-a:a;}

const int N=100005;
const int p=1000000007;
const ll p1=1000000006;
int f[N];

int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	int n,m,i;
	scanf("%d%d",&n,&m);
	if(n<m)swap(n,m);
	f[1]=1;f[2]=2;
	for(i=3;i<=n;++i)if((f[i]=f[i-1]+f[i-2])>=p)f[i]-=p;
	printf("%I64d",(((f[n]+f[m])+p1)<<1)%p);
	return 0;
}