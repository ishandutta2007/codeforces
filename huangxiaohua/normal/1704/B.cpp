#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,res,mx,mn,a[1005000];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		res=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		mn=mx=a[1];
		for(i=1;i<=n;i++){
			mx=max(mx,a[i]);
			mn=min(mn,a[i]);
			if(mx-mn>m+m){
				res++;
				mx=mn=a[i];
			}
		}
		cout<<res<<'\n';
	}
}