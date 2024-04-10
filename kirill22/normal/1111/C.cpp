#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> m;
ll f(ll k,ll a,ll b,ll l,ll r){
	if (k==0){
		return a;
	}

	if (l==r){
		return k*b*1;
	}
	ll mid=(l+r)/2;
	ll co=0;
	

	ll lo=0,ro=m.size()-1;
	if (m[m.size()-1]<l){
		return  min((r-l+1)*b*k,f (co,a,b,l,mid)+f (k-co,a,b,mid+1,r));
	}
	 while ((lo < ro)) {
	 	ll mi = (lo + ro) / 2;
	 	if (m[mi] >= l) {
	 		ro = mi; 
	 	}
        else {
        	lo = mi+1 ;
        }
     
	 }
	 ll lox=0,rox=m.size()-1;
	 if (m[0]>mid){
		return  min((r-l+1)*b*k,f (co,a,b,l,mid)+f (k-co,a,b,mid+1,r));
	}
	 while ((lox < rox)) {
	 	ll mi = (lox + rox) / 2;
	 	if (m[mi] <= mid){ 
	 		lox = mi; 
	 		if (lox==rox-1){
	 			if (m[rox]<=mid){
	 				lox++;
	 				continue;
	 			}
	 			rox--;
	 		}
	 	}
        else{
        	
         rox = mi-1 ;
        }
	 
	 }
	 ll j=0;
	 co=max(j,rox-ro+1);
	
	
	return  min((r-l+1)*b*k,f (co,a,b,l,mid)+f (k-co,a,b,mid+1,r));
}
int main(){
    ll n,k,a,b;
    cin >> n >> k >> a >> b;
    
    m.resize(k);
    for(int i=0;i<k;i++){
    	cin >> m[i];
    }
    sort(m.begin(),m.end());
    ll i=1;
    for(int ii=1;ii<=n;ii++){
    	i*=2;
    }
    
    
    
    cout << f (k,a,b,1,i); 

}