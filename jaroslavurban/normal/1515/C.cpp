#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	int tc;cin>>tc;
	while(tc--){
		int n,m,x;cin>>n>>m>>x;
		cout<<"YES\n";
		priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
		for(int i=0;i<m;++i)q.push({0,i});
		for(int i=0;i<n;++i){
			auto[s,u]=q.top();q.pop();
			cout<<u+1<<" ";
			int h;cin>>h;
			q.push({s+h,u});
		}
		cout<<"\n";
	}
}