#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 998244353
ll i,j,k,n,m,t,x,y,a[1005000];
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll res,sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		m=0;
		x=y=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			m+=a[i];
		}
		for(i=1;i<=n-m;i++){
			x+=a[i];
		}
		res=0;
		for(i=1;i<=x;i++){
			sb=i*i%M*ksm((n*(n-1)/2)%M,M-2)%M;
			sb=ksm(sb,M-2);
			res+=sb;res%=M;
		}
		cout<<res<<'\n';
	}
}