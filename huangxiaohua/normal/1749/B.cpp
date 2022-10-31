#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t;
ll res,mx;

int main(){
    ios::sync_with_stdio(0);
    cin>>t;
    while(t--){
    	cin>>n;
    	mx=res=0;
    	for(i=1;i<=n;i++){
    		cin>>k;res+=k;
		}
		for(i=1;i<=n;i++){
    		cin>>k;res+=k;
    		mx=max(mx,k);
		}
		cout<<res-mx<<'\n';
	}
}