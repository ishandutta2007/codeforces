#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[200500];


int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		k=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1)k++;
		}
		sort(a+1,a+n+1);
		if(!k){
			cout<<"YES\n";continue;
		}
		if(!a[1]){
			cout<<"NO\n";continue;
		}
		for(j=1;j<n;j++){
			if(a[j]+1==a[j+1]){
				cout<<"NO\n";goto aaa;
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}