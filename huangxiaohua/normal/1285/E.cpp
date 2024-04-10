#include <bits/stdc++.h>
using namespace std;
int i,j,k,n,m,t,it,res,f[200500],cnt[200500];
int main(){
	cin>>t;
	while(t--){
		vector<pair<int,int> >v;vector<int> s;
		for(i=1,cin>>n;i<=n;i++){cin>>j>>k;v.push_back({j,k});}
		sort(v.begin(),v.end());
		it=i=0;f[0]=-2e9;
		for(auto [l,r]:v){i++;cnt[i]=cnt[i-1]+(f[i-1]<l);f[i]=max(f[i-1],r);}
		reverse(v.begin(),v.end());res=cnt[n-1];i=n;
		for(auto [l,r]:v){if(i==1){break;}while(!s.empty()&&s.back()+r>=0){s.pop_back();}s.push_back(-l);k=cnt[i-2]+lower_bound(s.begin(),s.end(),-f[i-2])-s.begin();res=max(res,k);i--;}
		cout<<res<<'\n';
	}
}