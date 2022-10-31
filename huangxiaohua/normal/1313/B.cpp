#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,x,y,z,r1,r2;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>x>>y;
		if(x>y)swap(x,y);
		r1=r2=0;
		if((x+y)<=n){
			r1=1;
		}
		else if((x+y)>=(n+n-1)){
			r1=n;
		}
		else r1=x+y-n+1;
		r2+=min(n+1,x+y)-1;
		cout<<r1<<' '<<r2<<'\n';
	}
}