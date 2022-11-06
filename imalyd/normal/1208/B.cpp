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
const int N=2005;
int a[N];
set<int>S;
int main(){
	int n,s,i,j;
	scanf("%d",&n);s=n;
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	for(i=0;i<=n;++i){
		S.clear();
		for(j=1;j<=i;++j){
			if(S.count(a[j]))break;
			S.insert(a[j]);
		}
		if(j<=i)break;
		for(j=n;j>i;--j){
			if(S.count(a[j]))break;
			S.insert(a[j]);
		}
//		printf("i=%d j=%d\n",i,j);
		cmin(s,j-i);
	}
	printf("%d",s);
	return 0;
}