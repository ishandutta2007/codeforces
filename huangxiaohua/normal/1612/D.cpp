#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll x,y,z;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>x>>y>>z;
		if(x==z||y==z){
			cout<<"YES\n";
			continue;
		}
		while(1){
			if(x<y){
				swap(x,y);
			}
			if(x==z){
				cout<<"YES\n";
				goto aaa;
			}
			if(!y){
				cout<<"NO\n";
				goto aaa;
			}
			if(x<z){
				cout<<"NO\n";
				goto aaa;
			}
			if(((x-z)%y)==0){
				cout<<"YES\n";
				goto aaa;
			}
			x%=y;
		}
		aaa:;
	}
}