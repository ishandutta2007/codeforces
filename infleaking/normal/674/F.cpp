#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,p,q;
unsigned C[200];
unsigned a[200],Ans;
ll gcd(ll a,ll b){
	return b?gcd(b,a%b):a;
}
int main(){
	cin>>n>>p>>q;
	C[0]=1;
	for (int i=1;i<=p;i++){
		a[i]=n-i+1;
		unsigned A=1;
		for (int j=1,x=i;j<=i;j++){
			int d=gcd(x,a[j]);
			x/=d,a[j]/=d;
			A=A*a[j];
		}
		C[i]=A;
	}
	for (unsigned d=1;d<=q;d++){
		unsigned pw=1,ans=0;
		for (int i=0;i<=p&&i<n;i++)
			ans+=pw*C[i],pw*=d;
		Ans^=ans*d;
	}
	cout<<Ans<<endl;
}