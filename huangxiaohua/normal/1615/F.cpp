#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007
int i,j,k,n,m,t,a1[2050],a2[2050],b1[2050],b2[2050];
ll jc[10050],inv[10050],res;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

ll get(ll a1,ll b1,ll a2,ll b2){
	a1-=a2;
	if(a1>=0)return c(b1+b2,b2-a1);
	a1*=-1;
	return c(b1+b2,b1-a1);
}

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=10000;i++){jc[i]=jc[i-1]*i%M;}
	inv[10000]=ksm(jc[10000],M-2);
	for(i=9999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		string s1,s2;
		cin>>n>>s1>>s2;s1="X"+s1;s2="X"+s2;
		for(i=2;i<=n;i+=2){
			if(s1[i]!='?')s1[i]^=1;
			if(s2[i]!='?')s2[i]^=1;
		}
		for(i=1;i<=n;i++){
			a1[i]=a1[i-1]+(s1[i]=='1');
			b1[i]=b1[i-1]+(s1[i]=='?');
			a2[i]=a2[i-1]+(s2[i]=='1');
			b2[i]=b2[i-1]+(s2[i]=='?');
		}
		res=0;
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++){
				if(s1[i]=='0'||s2[j]=='0')continue;
				res=su(res,1ll*abs(i-j)*get(a1[i-1],b1[i-1],a2[j-1],b2[j-1])%M*get(a1[n]-a1[i],b1[n]-b1[i],a2[n]-a2[j],b2[n]-b2[j])%M );
			}
		}
		cout<<res<<'\n';
	}
}