#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;set<int> s;
		for(i=1;i<=n;i++){
			cin>>k;s.insert(k);
		}
		for(i=1;i<=n;i++)cout<<max((int)s.size(),i)<<' ';
		cout<<'\n';
	}
}