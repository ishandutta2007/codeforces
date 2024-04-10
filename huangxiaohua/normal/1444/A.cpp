#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int j,k,n,t;
ll a,b,c,d,an,bn,i;
 
ll ksm(ll a,ll p){
	ll res=1;
	while(p){
		if(p&1){res=res*a;}a=a*a;p>>=1;
	}return res;
}
 
vector<ll> res;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld%lld",&a,&b);d=b;
		if(a%b){printf("%lld\n",a);continue;}
		res.clear();
		for(i=2;i*i<=d;i++){
			if((b%i)==0){
				c=a;an=bn=0;
				while((b%i)==0){b/=i;bn++;}
				while((c%i)==0){c/=i;an++;}
				if(an>=bn){res.push_back(ksm(i,an-bn+1));}
			}
		}
		if(b-1){
			c=a;bn=1;an=0;
			while((c%b)==0){c/=b;an++;}
			if(an>=bn){res.push_back(ksm(b,an-bn+1));}
		}
		sort(res.begin(),res.end());
		printf("%lld\n",a/res[0]);
	}
}