#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,res,a[200050];

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int> f;
		f[0]=1;
		for(i=1;i<=n;i++){
			cin>>a[i];
			f[i+a[i]]|=f[i-1];
			f[i]|=f[i-a[i]-1];
		}
		if(f[n]){
			cout<<"YES\n";
		}
		else cout<<"NO\n";
	}
}