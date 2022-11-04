#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n;cin>>n;
	vector<int>dists(n);
	cout<<"? 1"<<endl;
	for(int i=0;i<n;++i)cin>>dists[i];
	vector<pair<int,int>>eds;
	int cnts[2]={};
	for(int i=1;i<n;++i)++cnts[dists[i]&1];
	int want=cnts[0]>cnts[1];
	for(int i=1;i<n;++i)
	if((dists[i]&1)==want){
		cout<<"? "<<i+1<<endl;
		for(int j=0;j<n;++j){
			int a;cin>>a;
			if(a==1)eds.push_back({i,j});
		}
	}else if(dists[i]==1)eds.push_back({0,i});
	assert(eds.size()==n-1);
	cout<<"!"<<endl;
	for(auto[u,v]:eds)cout<<u+1<<" "<<v+1<<endl;
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	//cin>>tc;
	while(tc--)ProGamerMove();
}