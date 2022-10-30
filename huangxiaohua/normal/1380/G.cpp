#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t;
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll a[300500],inv;

ll chk(int x,int y){
	if(y>=x)return a[x];
	int i,t1=x/y;ll ans=0;
	for(i=1;i<=t1;i++)ans=su(ans,su(a[x-(i-1)*y],M-a[x-i*y])*i%M);
	ans=su(ans,a[x-(i-1)*y]*i%M);
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;inv=ksm(n,M-2);
	for(i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(i=2;i<=n;i++)a[i]=su(a[i],a[i-1]);
	for(i=1;i<=n;i++)cout<<chk(n-i,i)*inv%M<<' ';
}