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

const int N=200005;

int n,l,f=1,s,a[N],b[N];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)if(b[i]==1){
		for(int j=i;j<=n;j++)if(b[j]!=j-i+1)f=0;
		if(f==1)l=n-i+1;
		break;
	}
	if(f==1){
		for(int i=1;i<=n-l;i++)if(b[i]&&b[i]<=l+i){f=0;break;}
		if(f==1){printf("%d",n-l);return 0;}
	}
	for(int i=1;i<=n;i++)if(b[i])s=max(s,i-b[i]+1);
	printf("%d",s+n);
	return 0;
}