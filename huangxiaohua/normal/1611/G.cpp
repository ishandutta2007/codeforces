#include <bits/stdc++.h>
using namespace std;
#define s1 s[i&1]
#define NMSL -1000000000
int i,j,k,n,m,t,res,cur;
vector<int> v[2005000];
char ss[1005000];
multiset<int> s[2];
int main(){
	cin>>t;
	while(t--){
		s[0].clear();s[1].clear();
		s[0].insert(NMSL);s[1].insert(NMSL);
		cin>>n>>m;
		for(i=1;i<=n+m;i++)v[i].clear();
		for(i=1;i<=n;i++){
			cin>>ss+1;for(j=1;j<=m;j++)if(ss[j]=='1')v[i+j].push_back(i-j);
		}
		res=0;
		for(i=1;i<=n+m;i++){
			for(auto j:v[i]){
				auto t=s1.upper_bound(j);
				t--;
				if((*t)!=NMSL)s1.erase(t);
				else res++;
				s1.insert(j);
			}
		}
		cout<<res<<'\n';
	}
}