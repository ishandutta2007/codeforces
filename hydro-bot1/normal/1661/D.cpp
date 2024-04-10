// Hydro submission #628f2e4737e0de7afd38d77e@1653550663860
#include <bits/stdc++.h>
using namespace std;
#define LL long long
LL n,k,a[999999],p,s,A,B;
int main(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i;i--){
		p-=s,s-=a[i+k],a[i]-=p;
		if(i>k)
			a[i]=max(0.0,ceil(1.0*a[i]/k)),A+=a[i],p+=a[i]*k,s+=a[i];
		else
			B=max(B,(a[i]-1)/i+1);
	}
	cout<<A+B;
	return 0;
}