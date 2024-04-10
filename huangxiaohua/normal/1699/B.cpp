#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		for(i=0;i<n;i++){
			for(j=0;j<m;j++){
				if((i%4)==0||(i%4)==3){
					k=((j%4)==0)||((j%4)==3);
				}
				else{
					k=((j%4)==1)||((j%4)==2);
				}
				cout<<k<<' ';
			}
			cout<<endl;
		}
	}
}