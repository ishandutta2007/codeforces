#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,sb;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m<n){
			cout<<"No\n";continue;
		}
		sb=m-(n-1);
		if((n-1)&1){
			if(!(m&1)){
				cout<<"Yes\n";
				for(i=1;i<n-1;i++){
					cout<<1<<' ';
				}
				cout<<(m-n+2)/2<<' '<<(m-n+2)/2<<'\n';
				continue;
			}
			cout<<"No\n";continue;
		}
		else{
			cout<<"Yes\n";
			for(i=1;i<n;i++){
				cout<<1<<' ';
			}
			cout<<sb<<'\n';
		}
	}
}