#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353
int i,j,k,n,m,t;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(m>((n+1)/2)){
			cout<<"-1\n";
		}
		else{
			for(i=1;i<=n;i++){
				for(j=1;j<=n;j++){
					if(m&&(i&1)&&(i==j)){
						cout<<'R';
						m--;
					}
					else{
						cout<<'.';
					}
					
				}
				cout<<'\n';
			}
			cout<<'\n';
		}
	}
}