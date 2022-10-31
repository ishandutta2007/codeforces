#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
ll M,a[666][666],d;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll su(ll a,ll b){a+=b;return (a>=M)?a-M:a;}

int main() {
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>a[i][i];
		d=(-i*i+a[i][i])%n;
		d=(d%n+n)%n;
		for(j=1;j<=n;j++){
			a[i][j]=(i*j+d)%n;
		}
	}
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			cout<<a[i][j]<<' ';
		}
		cout<<'\n';
	}
}