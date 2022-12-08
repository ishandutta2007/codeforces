#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
inline int add(int a,int b){a+=b;return a>=mod?a-mod:a;}
inline int sub(int a,int b){a-=b;return a<0?a+mod:a;}
inline int mul(int a,int b){return (ll)a*b%mod;}
inline int qpow(int a,int b){int ret=1;for(;b;b>>=1,a=mul(a,a))if(b&1)ret=mul(ret,a);return ret;}
/* math */
const int NN=5010;
int n,k;
int s[NN][NN];
int fac[NN],ifac[NN];
inline void init(int n=5000){
	fac[0]=ifac[0]=1;for(int i=1;i<=n;i++)fac[i]=mul(fac[i-1],i);
	ifac[n]=mul(fac[n],mod-2);for(int i=n-1;i;i--)ifac[i]=mul(ifac[i+1],i+1);
	s[0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			s[i][j]=add(s[i-1][j-1],mul(j,s[i-1][j]));
		}
	}
}
int main()
{
	cin >> n >> k;
	init();
	int facc=1;
	int ans=0;
	for(int d=0;d<=k&&d<=n;++d){
		if(d>0)facc=mul(facc,n-d+1);
		int temp = mul(facc,mul(qpow(2,n-d),s[k][d]));
		ans=add(ans,temp);
	}
	cout << ans << endl;
}