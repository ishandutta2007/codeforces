#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int tmp;
ll i,j,k,n,res,sb,nn,nnn;

void get(ll i,ll n){
	nn=sqrt(n);
	for(ll j=nn,k;j>=i;j--){
		if(n%j)continue;
		k=n/j;
		if(i+j<=k)break;
		if((i+j+k)&1)continue;
		if(i==j&&i==k){res++;continue;}
		if(i==j||i==k||j==k){res+=3;continue;}
		res+=6;
	}
}

int main(){
	cin>>n;
	if(n%3){puts("0");return 0;}
	n/=3;
	nnn=(ll)(pow(n,1.0/3)+0.5);
	for(k=1;k<=nnn;k++){
		sb=n/k;
		if(sb*k!=n)continue;
		get(k,sb);
	}
	cout<<res;
}