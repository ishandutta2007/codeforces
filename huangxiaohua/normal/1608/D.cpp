#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t,aw,ab,bw,bb;
ll jc[1005000],inv[1005000];
ll ksm(ll a,int p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll c(int n,int m){if(n<0||m<0||n<m){return 0;}return jc[n]*inv[m]%M*inv[n-m]%M;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll res;
string s[100500];

int main() {
	jc[0]=inv[0]=1;
	for(i=1;i<=1000000;i++){jc[i]=jc[i-1]*i%M;}
	inv[1000000]=ksm(jc[1000000],M-2);
	for(i=999999;i>=1;i--){inv[i]=inv[i+1]*(i+1)%M;}
	ios::sync_with_stdio(0);
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>s[i];
		if(s[i][0]=='W'){aw++;}
		if(s[i][0]=='B'){ab++;}
		if(s[i][1]=='W'){bw++;}
		if(s[i][1]=='B'){bb++;}
	}
	for(i=0;i<=n;i++){
		ll t1=c(n-aw-ab,i-aw)*c(n-bw-bb,i-bb)%M;
		res=su(res,t1);
	}
	aw=bw=bb=ab=0;
	for(i=1;i<=n;i++){
		if(s[i]=="WW"||s[i]=="BB")goto aaa;
		if(s[i][0]=='W')s[i][1]='B';
		if(s[i][0]=='B')s[i][1]='W';
		if(s[i][1]=='W')s[i][0]='B';
		if(s[i][1]=='B')s[i][0]='W';
		if(s[i][0]=='W'){aw++;}
		if(s[i][0]=='B'){ab++;}
		if(s[i][1]=='W'){bw++;}
		if(s[i][1]=='B'){bb++;}
	}
	res=su(res,M-ksm(2,n-aw-ab));
	if(!aw)res++;
	if(!ab)res++;
	res%=M;
	aaa:;
	cout<<res%M;
}