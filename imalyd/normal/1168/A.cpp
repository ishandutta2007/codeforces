//#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
#define ll long long
//#define I inline
//#define R register int
namespace io{
    const int l=1<<19;
    char buf[l],*s,*t,c;
    char gc(){
        if(s==t){
            t=(s=buf)+fread(buf,1,l,stdin);
            return s==t?EOF:*s++;
        }
        return *s++;
    }
    template<class IT>void gi(IT &x){
        x=0;c=gc();while(c<'0'||c>'9')c=gc();
        while('0'<=c&&c<='9'){x=(x<<1)+(x<<3)+(c^48);c=gc();}
    }
};
using io::gi;
template<class IT>void chkmin(IT &a,IT b){if(b<a)a=b;}
template<class IT>void chkmax(IT &a,IT b){if(a<b)a=b;}

const int N=300005;

int n,m,a[N];
int chk(int v){
	int i,mx=0;
	for(i=1;i<=n;++i){
		if(a[i]<m-v){
			if(mx<a[i])mx=a[i];
			else if(mx<=a[i]+v);
			else return 0;
		}else{
			if(mx<=a[i]+v-m);
			else if(mx<a[i])mx=a[i];
			else;
		}
	}
	return 1;
}
int main(){
	scanf("%d%d",&n,&m);
	int i,l=0,r=m,mid,ans;
	for(i=1;i<=n;++i)scanf("%d",&a[i]);
	while(l<=r){
		mid=(l+r)>>1;
		if(chk(mid)){ans=mid;r=mid-1;}
		else l=mid+1;
	}
	printf("%d",ans);
	return 0;
}