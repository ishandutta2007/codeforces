#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll MOD=1e18;
int main() {
    ll n,b;
    MOD+=5;
    cin >> n >> b;
    ll co=-1;
    ll a=b;

    for(ll i=2;i*i<=b;i++){
    	ll c=0;
    	
    	while(a%i==0){
    		a/=i;
    		c++;
    	}
    	if (c!=0){
    		ll ii=i,cou=0;
    		while(ii<=n){
    			cou+=n/ii;
    			if (ii>MOD/i){
    				break;
    			}
    			ii*=i;
    		}
    		if (co==-1){
    			co=cou/c;
    		}
    		else{
    			co=min(co,cou/c);
    		}
    	}
    	
    }
    if (a!=1){
    	ll ii=a,cou=0;
    	while(ii<=n){
    			cou+=n/ii;
    				if (ii>MOD/a){
    				break;
    			}
    			ii*=a;
    		}
    		if (co==-1){
    			co=cou;
    		}
    		else{
    			co=min(co,cou);
    		}
    	
    	
    }
ll j=0;
    cout << max(j,co);
    


}