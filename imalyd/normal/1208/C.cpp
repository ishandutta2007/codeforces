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
		while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^'0');c=gc();}
	}
};
using io::gi;
struct qwq{
	int a,b;
	inline bool operator<(const qwq &x)const{
		return a<x.a;
	}
};
template<class IT>inline void cmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>inline void cmax(IT &a,IT b){if(a<b)a=b;}
const ll p=1000000007ll,inf=1000000000000000000ll;
const int N=200005;

int main(){
	int n,m,l,r,t,i,j,cnt=0;
	scanf("%d",&n);m=n>>2;l=0;t=r=n<<2;
	for(i=0;i<m;++i){
		for(j=l;j<r;j+=4)printf("%d ",j  );printf("\n");
		for(j=l;j<r;j+=4)printf("%d ",j|1);printf("\n");
		for(j=l;j<r;j+=4)printf("%d ",j|2);printf("\n");
		for(j=l;j<r;j+=4)printf("%d ",j|3);printf("\n");
		l+=t;r+=t;
	}
	return 0;
}