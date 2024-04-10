#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int i,j,k,n,m,t;
string s1,s2;
ll res;

int main() {
	ios::sync_with_stdio(0);
	cin>>t;
	while(t--){
		cin>>n>>s1>>s2;
		s1="X"+s1+"0";s2="X"+s2+"0";
		if(s1[1]!=s2[1]||s1[n]!=s2[n]){
			cout<<"-1\n";continue;
		}
		vector<pair<int,int> >v1,v2;
		j=k=0;
		for(i=1;i<=n+1;i++){
			if(s1[i]=='1'){
				if(!j)j=i;
				k=i;
			}
			else if(j){
				v1.push_back({j,k});
				j=k=0;
			}
		}
		j=k=0;
		for(i=1;i<=n+1;i++){
			if(s2[i]=='1'){
				if(!j)j=i;
				k=i;
			}
			else if(j){
				v2.push_back({j,k});
				j=k=0;
			}
		}
		if(v1.size()!=v2.size()){
			cout<<-1<<'\n';continue;
		}
		res=0;
		m=v1.size();
		for(i=0;i<m;i++){
			auto [l1,r1]=v1[i];
			auto [l2,r2]=v2[i];
			//printf("NMSL%d %d %d %d\n",l1,r1,l2,r2);
			res+=abs(l1-l2)+abs(r1-r2);
		}
		cout<<res<<'\n';
	}
}