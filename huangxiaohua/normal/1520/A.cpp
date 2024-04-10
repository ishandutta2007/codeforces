#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#pragma GCC optimize(2)

int i,j,n,m,k,t,res,sb,mp[1005];
char s[100];
int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s+1;
		memset(mp,0,sizeof(mp));
		for(i=1;i<=n;i++){
			if(mp[s[i]]&&i!=mp[s[i]]+1){cout<<"NO"<<endl;goto aaa;}
			mp[s[i]]=i;
		}
		cout<<"YES"<<endl;
		aaa:;
	}
}