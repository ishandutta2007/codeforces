#include<bits/stdc++.h>
using namespace std;
long long n,k;
long long a[100001];
long long ans;
int main(){
    cin>>n>>k;
    for(long long i=1;i<=n;i++){
    	cin>>a[i];
	}
    sort(a+1,a+n+1);
	ans=a[n]-a[1];
    for(long long l=1,r=n,x;l<r&&k;ans-=x){
    	if(l<=n-r){
    		x=min(a[l+1]-a[l],k/l);
    		k-=x*l;
    		l++;
		}
		else{
			x=min(a[r]-a[r-1],k/(n-r+1));
			k-=x*(n-r+1);
			r--;
		}
	}
    cout<<ans;
    return 0;
}