#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0);ios::sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m;cin>>n>>m;
		vector<ll>mem(n),pts(n);
		for(int i=0;i<n;++i)cin>>mem[i];
		for(int i=0;i<n;++i)cin>>pts[i];
		vector<ll>mem1,mem2;
		for(int i=0;i<n;++i)if(pts[i]==1)mem1.push_back(mem[i]);
		else mem2.push_back(mem[i]);
		sort(mem1.rbegin(),mem1.rend());
		sort(mem2.rbegin(),mem2.rend());
		partial_sum(mem1.begin(),mem1.end(),mem1.begin());
		partial_sum(mem2.begin(),mem2.end(),mem2.begin());
		int res=1e9;
		auto it=lower_bound(mem1.begin(),mem1.end(),m);
		if(it!=mem1.end())res=it-mem1.begin()+1;
		for(int i=0;i<mem2.size();++i){
			it=lower_bound(mem1.begin(),mem1.end(),m-mem2[i]);
			if(it!=mem1.end()||mem2[i]>=m)res=min(res,2*(i+1)+int(it-mem1.begin())+(mem2[i]<m));
		}
		cout<<(res==1e9?-1:res)<<endl;
	}
}