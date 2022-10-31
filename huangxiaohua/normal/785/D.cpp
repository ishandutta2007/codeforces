#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007
int i,j,k,n,m,t;
ll jc[505000],inv[505000],l[200500],r[200500],res;
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
char s[200500];

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=500000;i++){jc[i]=jc[i-1]*i%M;}
	inv[500000]=ksm(jc[500000],M-2);
	for(i=499999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	
	gets(s+1);n=strlen(s+1);
	for(i=n;i>=1;i--){
		r[i]=r[i+1]+(s[i]==')');
	}
	for(i=1;i<=n;i++){
		l[i]=l[i-1];
		if(s[i]=='('){
			l[i]++;
			res+=c(l[i]+r[i+1]-1,r[i+1]-1);
		}
	}
	printf("%lld",res%M);
}