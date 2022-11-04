#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

struct P{
	int i,j,w;
};
bool operator<(const P&a,const P&b){return tie(a.w,a.i,a.j)<tie(b.w,b.i,b.j);}

main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m;cin>>n>>m;
		set<P>paths;
		for(int i=0;i<n;++i)
			for(int j=0;j<m;++j){
				int w;cin>>w;paths.insert({i,j,w});
			}
		int bst=0;
		vector<int>cur(n);
		vector<vector<int>>f(n,vector<int>(m,-1));
		cerr<<paths.size()<<endl;
		for(auto[i,j,w]:paths){
			if(bst<m){
				f[i][bst++]=w;
			}
			else{
				while(~f[i][cur[i]])++cur[i];
				f[i][cur[i]]=w;
			}
		}
		for(int i=0;i<n;++i,cout<<endl)
			for(int j=0;j<m;++j)
				cout<<f[i][j]<<" ";
	}
}