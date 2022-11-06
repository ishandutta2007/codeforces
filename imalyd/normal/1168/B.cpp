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

int n,f0;
long long ans;
char s[N];
int main(){
	scanf("%s",s+1);
	n=strlen(s+1);
	for(int i=1;i<=n;i++){
		f0=0;
		if(i+8<n){
			for(int j=i;j<=i+8;j++){
				if(f0==0)for(int k=j-2;k>=i;k-=2){
					if(s[j]==s[k]&&s[j]==s[(j+k)>>1]){f0=1;break;}
				}
				if(f0==1)++ans;
			}
			ans+=n-i-8;
		}else{
			for(int j=i;j<=n;j++){
				if(f0==0)for(int k=j-2;k>=i;k-=2){
					if(s[j]==s[k]&&s[j]==s[(j+k)>>1]){f0=1;break;}
				}
				if(f0==1)++ans;
//				printf("i=%d j=%d f0=%d\n",i,j,f0);
			}
		}
	}
	printf("%I64d",ans);
	return 0;
}