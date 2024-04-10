#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res;
string s[666];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		k=res=0;
		for(i=1;i<=n;i++){
			cin>>s[i];
			for(auto &j:s[i]){
				j-='0';
				k+=j;
			}
			s[i]="X"+s[i];
		}
		for(i=1;i<n;i++){
			for(j=1;j<m;j++){
				res=max(res, k-s[i][j]-s[i+1][j]-s[i][j+1]-s[i+1][j+1]+min(2,s[i][j]+s[i+1][j]+s[i][j+1]+s[i+1][j+1]) );
			}
		}
		cout<<res<<'\n';
	}
}