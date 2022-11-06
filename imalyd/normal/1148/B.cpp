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

const int N=400005;

int n,m,ta,tb,k,a[N],b[N],ans;

int main(){
	scanf("%d%d%d%d%d",&n,&m,&ta,&tb,&k);
	if(k>=n||k>=m){printf("-1");return 0;}
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=m;i++)scanf("%d",&b[i]);
//	printf("k=%d\n",k);
	for(int i=0;i<=k;i++){
		int id=lower_bound(b+1,b+m+1,a[i+1]+ta)-b;
//		printf("i=%d a=%d id=%d\n",i,a[i+1]+ta,id);
		if(id+(k-i)<=m)ans=max(ans,id+(k-i));
		else{printf("-1");return 0;}
	}
	printf("%d",b[ans]+tb);
	return 0;
}