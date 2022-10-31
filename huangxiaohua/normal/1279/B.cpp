#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,t;
ll su,m,a[100500],res,mx;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=1;i<=n;i++){
			cin>>a[i];
		}
		res=0;mx=0;
		su=0;
		for(i=1;i<=n;i++){
			su+=a[i];
			if((su-max(mx,a[i]))>m){
				cout<<res<<'\n';goto aaa;
			}
			if(a[i]>mx){
				mx=a[i];res=i;
			}
		}
		if(su<=m){
			cout<<"0\n";
		}
		else{
			cout<<res<<'\n';
		}
		aaa:;
	}
}