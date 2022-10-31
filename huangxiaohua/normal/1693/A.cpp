#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500],ed;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll su=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			su+=a[i];
		}
		if(su){
			cout<<"No\n";continue;
		}
		su=0;
		ed=0;
		for(i=1;i<=n;i++){
			su+=a[i];
			if(su<0){
				cout<<"No\n";goto aaa;
			}
			if(ed&&su){
				cout<<"No\n";goto aaa;
			}
			if(!su)ed=1;
		}
		cout<<"Yes\n";
		aaa:;
	}
}