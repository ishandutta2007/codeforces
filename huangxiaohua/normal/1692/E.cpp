#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],l,r,res;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++)cin>>a[i];
		res=1e9;
		l=1;k=0;
		for(i=1;i<=n;i++){
			k+=a[i];
			while(k>m){
				k-=a[l];l++;
			}
			if(k==m){
				res=min(res,n-(i-l+1));
			}
		}
		if(res>n)res=-1;
		cout<<res<<endl;
	}
}