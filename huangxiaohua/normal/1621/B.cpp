#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define M 998244353

int i,j,k,n,m,t;
ll mx,mn,r1,r2,r3,x,y,w;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		mx=-1;mn=1e18;r1=r2=r3=1e18;
		for(i=1;i<=n;i++){
			cin>>x>>y>>w;
			
			if(x==mn){
				r1=min(r1,w);
			}
			if(y==mx){
				r2=min(r2,w);
			}
			if(x==mn&&y==mx){
				r3=min(r3,w);
			}
			if(!(x>=mn&&y<=mx)){
				r3=1e18;
			}
			if(x<mn){
				mn=x;
				r1=w;
			}
			if(y>mx){
				mx=y;
				r2=w;
			}
			if(x==mn&&y==mx){
				r3=min(r3,w);
				goto aaa;
			}
			aaa:;
			cout<<min(r1+r2,r3)<<'\n';
		}
	}
}