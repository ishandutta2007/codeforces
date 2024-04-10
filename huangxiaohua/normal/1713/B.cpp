#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[1005000];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==a[i-1]){
				n--;i--;
			}
		}
		for(i=2;i<n;i++){
			if(a[i]<a[i-1]&&a[i]<a[i+1]){
				cout<<"NO\n";goto aaa;
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}