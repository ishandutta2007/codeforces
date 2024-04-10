#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int m=5000000;

int i,j,k,n,t;
ll a[5005000],f[5005000],res;

int main(){
	cin>>n;
	for(i=1;i<=n;i++){
		cin>>k;
		a[k]++;
	}
	for(i=1;i<=m;i++){
		for(j=i+i;j<=m;j+=i){
			a[i]+=a[j];
		}
	}
	for(i=m;i>=1;i--){
		f[i]=a[i]*i;
		for(j=i;j<=m;j+=i){
			f[i]=max(f[i],(a[i]-a[j])*i+f[j]);
		}
		res=max(res,f[i]);
	}
	cout<<res;
}