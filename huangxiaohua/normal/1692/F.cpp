#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
ll a[200500],it;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		map<int,int> mp;
		it=0;
		for(i=1;i<=n;i++){
			cin>>k;k%=10;
			if(mp[k]<=3){
				mp[k]++;a[++it]=k;
			}
		}
		for(i=1;i<=it;i++)for(j=i+1;j<=it;j++)for(k=j+1;k<=it;k++){
			if(((a[i]+a[j]+a[k])%10)==3){
				cout<<"YES\n";goto aaa;
			}
		}
		cout<<"NO\n";
		aaa:;
	}
}