#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t,a[505000],sb;
ll jc[505000],inv[505000],tmp;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll res=0;

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=500000;i++){jc[i]=jc[i-1]*i%M;}
	inv[500000]=ksm(jc[500000],M-2);
	for(i=499999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i>1&&a[i]!=a[i-1]){sb++;}
	}
	if(a[n]!=a[1]){sb++;}
	
	for(i=1;i<=sb;i++){
		tmp=ksm(2,i);
		if(!(i&1)){
			tmp+=M-c(i,i/2);
			tmp%=M;
		}
		tmp=tmp*ksm(2,M-2)%M;
		
		tmp=tmp*c(sb,i)%M;
		//cout<<tmp<<' '<<ksm(m-2,sb-i)<<endl;
		res+=tmp*ksm(m-2,sb-i);
		res%=M;
	}
	
	res=res*ksm(m,n-sb)%M;
	printf("%lld",(res%M+M)%M);
}