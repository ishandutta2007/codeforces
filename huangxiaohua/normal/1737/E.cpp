#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
#define inv2 500000004
int i,j,k,n,m,t,l,r;
ll f[2000005],p[2000005];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		p[n+1]=0;
		f[n]=p[n]=1;
		for(i=n-1;i>=1;i--){
			l=i+1; r=min(n-1,i+i-1);
			f[i]=(p[l]+M-p[r+1]*ksm(inv2,r-l+1)%M)%M;
			if(i+i>n){
				f[i]+=ksm(inv2,n-i-1);
				f[i]%=M;
			}
			p[i]=((f[i]+p[i+1])*((M+1)/2))%M;
			
			//printf("NMSL%d %d %d\n",i,f[i],p[i]);
		}
		for(i=1;i<=n;i++){
			ll res=f[i]*ksm(inv2,(i-1)/2)%M;
			if(i!=n)res=res*inv2%M;
			cout<<res<<'\n';
		}
	}
}