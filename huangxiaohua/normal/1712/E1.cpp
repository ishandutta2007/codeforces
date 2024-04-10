#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,l,r,it;
ll res,f[500500],sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>l>>r;
		memset(f,0,sizeof(f));
		res=1ll*(r-l+1)*(r-l)*(r-l-1)/6;
		for(i=l;i<=r;i++){
			for(j=i;j<=r;j+=i)f[j]++;
		}
		for(i=l;i<=r;i++){
			res-=(f[i]-2)*(f[i]-1)/2;
			if(!(i%6)&&(i/2)>=l)res--;
			if(!(i%15)&&(i/5*2)>=l)res--;
			it++;
		}
		cout<<res<<'\n';
	}
}