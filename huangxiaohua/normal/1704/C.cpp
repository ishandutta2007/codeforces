#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,res,a[1005000];

int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>t;
	while(t--){
		res=0;
		cin>>n>>m;
		for(i=1;i<=m;i++)cin>>a[i];
		sort(a+1,a+m+1);
		a[m+1]=a[1]+n;
		vector<ll> v;
		for(i=1;i<=m;i++){
			v.push_back(a[i+1]-a[i]-1);
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		j=0;
		for(auto i:v){
			//cout<<"NMSL "<<i<<endl;
			if(i>j){
				res+=max(1ll,i-j-1);
			}
			j+=4;
		}
		cout<<n-res<<'\n';
	}
}