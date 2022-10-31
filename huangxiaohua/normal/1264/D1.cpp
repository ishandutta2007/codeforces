#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t;
ll res,l[1000050][3],r[1000050][3],p[1005000];
char s[1005000];
ll jc[1005000],inv[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	gets(s+1);
	n=strlen(s+1);
	for(i=n;i>=1;i--){
		r[i][1]=r[i+1][1];r[i][2]=r[i+1][2];
		if(s[i]==')'){r[i][1]++;}
		if(s[i]=='?'){r[i][2]++;}
	}
	for(i=1;i<=n;i++){
		l[i][1]=l[i-1][1];l[i][2]=l[i-1][2];
		if(s[i]=='('){l[i][1]++;}
		if(s[i]=='?'){l[i][2]++;}
		for(j=max(l[i][1],r[i+1][1]);j<=min(l[i][1]+l[i][2],r[i+1][1]+r[i+1][2]);j++){
			res+=c(l[i][2],j-l[i][1])*c(r[i+1][2],j-r[i+1][1])%M*j%M;
		}
	}
	printf("%lld",res%M);
}