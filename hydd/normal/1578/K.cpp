#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll k,n;
ll solve(ll k,ll n){
	int l=0; while ((1ll<<(l+1))<=n) l++;
	ll m=n-(1ll<<l)+1,tmp,tot;
	for (int i=l;i>=0;i--){//1<<l
		tmp=(1ll<<(l-i));
		tot=tmp-1+min(m,tmp);
		if (tot>=k){
			if (tmp-1>=k) return min(n,(1ll<<(i+1))-1);
			else if (tmp-1+m%tmp>=k) return min(n,(1ll<<i)+m/tmp);
			else return min(n,(1ll<<i)+m/tmp-1);
		}
	}
	return -233;
}
int main(){
	cin>>n>>k;
	cout<<max(solve(k+1,n)<<1,solve(k,n))<<endl;
	return 0;
}