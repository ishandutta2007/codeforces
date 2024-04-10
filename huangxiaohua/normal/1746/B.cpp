#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[666666];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		res=0;
		int l,r;
		l=1;r=n;
		while(l<r){
			if(a[l]==0){
				l++;continue;
			}
			if(a[r]==1){
				r--;continue;
			}
			res++;l++;r--;
		}
		cout<<res<<'\n';
	}
}