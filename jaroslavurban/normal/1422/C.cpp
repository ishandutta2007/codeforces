#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N=100100,mod=1e9+7;
int n;
string s;
int nr[N],nl[N];
int dp[N][3];

ll powermod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return powermod(a*a%mod,b/2)*a%mod;
	return powermod(a*a%mod,b/2);
}
main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>s;n=s.size();
	nr[n-1]=s[n-1]-'0';
	nl[0]=s[0]-'0';
	for(int i=n-2;i>=0;--i)nr[i]=((s[i]-'0')*powermod(10,n-i-1)+nr[i+1])%mod;
	for(int i=1;i<n;++i)nl[i]=(10*nl[i-1]+(s[i]-'0'))%mod;
	ll res=0;
	for(int i=n-1;i>=0;--i)res=(res+i*nr[i])%mod;
	ll lmao=1;
	for(int i=n-2;i>=0;--i){res=(res+lmao*nl[i])%mod;lmao=(lmao*10+1)%mod;}
	cout<<res<<endl;
}