#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a,b,c,d;
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		a=c=0;b=d=0;
		for(i=1;i<=n;i++){
			cin>>j>>k;
			a=max(a,j);
			b=min(b,j);
			c=max(c,k);
			d=min(d,k);
		}
		cout<<(abs(a)+abs(b)+abs(c)+abs(d))*2<<'\n';
	}
}