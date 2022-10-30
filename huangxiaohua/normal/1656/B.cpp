#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500];


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>m;
		map<int,int> mp;
		for(i=1;i<=n;i++){
			cin>>a[i];mp[a[i]]++;
		}
		for(i=1;i<=n;i++){
			if(mp[a[i]-m]){
				cout<<"YES\n";goto aaa;
			}
		}
		cout<<"NO\n";
		aaa:;
	}
}