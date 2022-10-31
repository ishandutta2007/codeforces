#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll i,j,k,n,m,t,a[100500],res[100500],sb[100500],l,r;

int main(){
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(i=1;i<=n;i++){
			cin>>a[i];
			res[i]=0;
		}
		m=0;
		vector<pair<ll,ll> >v;
		for(i=2;i<=n;i++){
			v.push_back({a[i]-a[i-1],i});
		}
		if(n==1){
			cout<<"1\n";continue;
		}
		sort(v.begin(),v.end());
		l=1;r=n;
		for(auto [w,id]:v){
			if(w>=0)break;
			w=-w;
			//printf("NMSL%d %d %d %d\n",l,r,w,id);
			if(w>r){
				res[l]=res[r]=id;l++;r--;
			}
			else{
				res[r]=id;r--;
			}
		}
		for(i=1;i<=n;i++){
			if(!res[i])res[i]=n;
			cout<<res[i]<<' ';
		}
		cout<<'\n';
	}
}