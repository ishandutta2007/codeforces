#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,x,y;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		bitset<105> a,b;
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>k;a[i]=k;
		}
		for(i=1;i<=n;i++){
			cin>>k;b[i]=k;
		}
		if(a==b){
			cout<<"0\n";continue;
		}
		x=a.count();y=b.count();
		if(x==y){
			cout<<"1\n";continue;
		}
		if((a&b)==a||(a&b)==b){
			cout<<abs(x-y)<<'\n';continue;
		}
		cout<<abs(x-y)+1<<'\n';
	}
}