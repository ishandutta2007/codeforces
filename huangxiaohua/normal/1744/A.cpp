#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t,a[666];
string s;

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++)cin>>a[i];
		cin>>s;s="X"+s;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				if(a[i]==a[j]&&s[i]!=s[j]){
					cout<<"NO\n";goto aaa;
				}
			}
		}
		cout<<"YES\n";
		aaa:;
	}
}