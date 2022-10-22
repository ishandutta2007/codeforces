#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100001];
int main(){
	cin>>t;
	while(t--){
		cin>>n;
		int ans=-1;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(!(a[i]&1)){
				ans=i;
			}
		}
		if(ans!=-1){
			cout<<1<<'\n'<<ans<<'\n';
		}
		else{
			if(n>=2){
				cout<<2<<'\n'<<"1 2"<<'\n';
			}
			else cout<<-1<<'\n';
		}
	}
	return 0;
}