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

int n,p,m,a[N],b[N],s[N<<3],t[N<<3];
void op(int i,int j){
	s[++m]=i;
	t[  m]=j;
	swap(b[a[i]],b[a[j]]);
	swap(  a[i] ,  a[j] );
}
int main(){
	scanf("%d",&n);p=n>>1;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)b[a[i]]=i;
	for(int i=1;i<=p;i++){
		int j=b[i];
		if(i==j)continue;
		if(j>=p+i)op(i,j);
		else if(j<=p){
			op(j,n);
			op(i,n);
		}else{
			op(1,j);
			op(1,n);
			op(i,n);
			op(1,j);
		}
	}
	for(int i=p+1;i<=n;i++){
		int j=b[i];
		if(i==j)continue;
		op(j,1);
		op(i,1);
		op(j,1);
	}
	printf("%d\n",m);
	for(int i=1;i<=m;i++)printf("%d %d\n",s[i],t[i]);
	return 0;
}