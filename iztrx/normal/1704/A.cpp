#include<bits/stdc++.h>
using namespace std;
#define mod 998244353
#define ll long long
#define IOS ios::sync_with_stdio(0)
#define N 1000005
ll ksm(ll x,ll y){ll ret=1;for(;y;y>>=1,x=x*x%mod)if(y&1)ret=ret*x%mod;return ret;}
void py(){cout<<"Yes\n";}
void pn(){cout<<"No\n";}
int T,n,m,i,j,k,fl,x,y,a[N];
char qwq,qaq;
string s,t;
int main(){
	IOS;
	cin>>T;
	while(T--){
		cin>>n>>m>>s>>t;qwq=0,qaq='1';
		for(i=0;i<=n-m;++i)qwq=max(qwq,s[i]),qaq=min(qaq,s[i]);
		if(qwq>=t[0]&&qaq<=t[0])fl=1;
		else fl=0;
		for(i=1;i<m;++i)if(s[i+n-m]!=t[i])fl=0;
		if(!fl)pn();
		else py();
	}
}