#include<cstring>
#include<cstdio>
#include<algorithm>
#define fo(i,a,b)for(int i=a,E=b;i<=E;i++)
#define fd(i,a,b)for(int i=b,E=a;i>=E;i--)
#define min(a,b)(a<b?a:b)
#define abs(x)(x>0?x:-(x))
#define ll long long
using namespace std;
const int N=1e5+5;
int n,d,b,a[N],c[N],nn,an,m,le,ri,bb,ba;
bool bz;
void R(int &n){
	char c;int fh=1;for(;(c=getchar())<'0'||c>'9';)if(c=='-')fh=-1;
	for(n=0;c<='9'&&c>='0';c=getchar())n=n*10+c-48;n*=fh;
}
int main(){
//	freopen("a.in","r",stdin);
	R(n);R(d);R(b);
	fo(i,1,n)R(a[i]);
	for(int l=0,r=n>>1,m;m=l+r>>1,l<=r;){
		bz=1;nn=n+1>>1;
		fo(i,1,n)c[i]=a[i];
		le=1;ri=n;
		fo(i,m+1,nn){
			int ii=n-i+1;
			bb=b;
			for(;le<=n;le++){
				if(abs(i-le)>(ll)d*i)continue;
				ba=min(bb,c[le]);
				bb-=ba;c[le]-=ba;
				if(!bb)break;
			}
			if(bb){bz=0;break;}
			if(ii!=i){
				bb=b;
				for(;ri;ri--){
					if(abs(ri-ii)>(ll)d*i)continue;
					ba=min(bb,c[ri]);
					bb-=ba;c[ri]-=ba;
					if(!bb)break;
				}
				if(bb){bz=0;break;}
			}
		}
		if(bz)an=m,r=m-1;else l=m+1;
	}
	printf("%d",an);
}