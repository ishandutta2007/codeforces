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
	int t,n,a,b;
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&a,&b,&n);
		if(!(n%3))printf("%d\n",a);
		else if(n%3==1)printf("%d\n",b);
		else printf("%d\n",a^b);
	}
	return 0;
}