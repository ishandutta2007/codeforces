#include<bits/stdc++.h>
using namespace std; 
#define ll long long
ll maxs=1e15;  
int main(){

	ll h,n; cin>>h>>n;

	int arr[n+1]={0}; for(int i=1;i<=n;i++) cin>>arr[i];

	ll mini=maxs; 

	ll sum=0,ans=0,rem=0;

	for(int i=1;i<=n;i++){
		sum+=arr[i];
		mini=min(mini,sum);
	}
	
	if(mini>=0) {
		cout<<-1<<endl; return 0; 
	}
		
	rem=h;		

	if(h>abs(mini)){
		if(sum>=0){
			cout<<-1<<endl; return 0; 
		}else{
			sum=-sum; 
			ans= (h+mini)/sum; 
			if((h+mini)%sum!=0) ans+=1;
			rem=h-sum*ans; 
		}

	}	

	// cout<<"rem "<<rem<<endl;

	for(int i=1;i<=n;i++){
		rem+=arr[i];
		if(rem<=0){
			cout<<ans*n+i<<endl; return 0; 	
		} 
	}


}