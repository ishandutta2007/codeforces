#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,ans;
int b[N];
string a[N];
map<string,int>mp,mp1;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		cin>>a[i];
		scanf("%d",b+i);
		mp[a[i]]+=b[i];
	}
	for(int i=1;i<=n;++i){
		ans=max(ans,mp[a[i]]);
	}
	for(int i=1;i<=n;++i){
		mp1[a[i]]+=b[i];
		if(mp[a[i]]==ans&&mp1[a[i]]>=ans){
			cout<<a[i];
			return 0;
		}
	}
	return 0;
}