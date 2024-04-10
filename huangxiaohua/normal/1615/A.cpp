#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y,z;


int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		ll sb=0;
		for(i=1;i<=n;i++){
			cin>>k;sb+=k;
		}
		ll res=((sb%n)!=0);
		cout<<res<<'\n';
	}
}