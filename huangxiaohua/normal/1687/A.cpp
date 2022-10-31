#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[200500],p[200500],res;

int main(void){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	res=0;
    	for(i=1;i<=n;i++){
    		cin>>a[i];
    		p[i]=p[i-1]+a[i];
		}
		if(m<=n){
			for(i=m;i<=n;i++)res=max(res,p[i]-p[i-m]);
			res+=1ll*m*(m-1)/2;
		}
		else{
			res=p[n];
			res+=1ll*n*(n+1)/2;
			res+=1ll*n*(m-n-1);
		}
		cout<<res<<'\n';
	}
}