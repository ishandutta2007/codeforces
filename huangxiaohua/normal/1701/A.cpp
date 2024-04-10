#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		k=0;
		for(i=1;i<=4;i++){
			cin>>j;k+=j;
		}
		if(k==4)cout<<2<<endl;
		else if(k==0) cout<<0<<endl;
		else cout<<1<<endl;
	}
}