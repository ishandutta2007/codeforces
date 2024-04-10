#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		if(n==1&&m==1){
			cout<<"0\n";continue;
		}
		cout<<n+m+min(n,m)-2<<'\n';
	}
}