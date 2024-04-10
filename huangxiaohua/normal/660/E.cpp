#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 1000000007

int i,j,k,n,m,t;
ll res,sb;

ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

int main() {
	cin>>n>>m;
	if(n==1){
		printf("%lld",m*2);return 0;
	}
	res=ksm(m,n)*2%M;
	sb=m;
	for(i=2;i<=n;i++){
		sb=sb*(m+m-1)%M;
		res=su(res,sb*ksm(m,n-i)%M);
	}
	cout<<res;
}