#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M 1000000007

int i,j,k,n,m,t;
ll sb,res=1;
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}

ll get(int x,ll sb){
	ll res=0;
	while(sb){
		res+=sb/x;sb/=x;
	}
	return res;
}

int main(){
	scanf("%d%lld",&n,&sb);
	for(i=2;i*i<=n;i++){
		if(!(n%i)){
			while(!(n%i)){n/=i;}
			res=res*ksm(i,get(i,sb))%M;
		}
	}
	if(n>1){
		res=res*ksm(n,get(n,sb))%M;
	}
	cout<<res;
}