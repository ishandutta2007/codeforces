#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,k;cin>>n>>k;
	vector<int>a(n);
	vector<vector<int>>pos(n);
	for(int i=0;i<n;++i)cin>>a[i],pos[--a[i]].push_back(i);
	vector<int>res(n),lft;
	for(int i=0;i<n;++i){
		if(pos[i].size()>=k){
			for(int j=0;j<k;++j)res[pos[i][j]]=j+1;
		}else lft.insert(lft.end(),pos[i].begin(),pos[i].end());
	}
	while(lft.size()%k)lft.pop_back();
	for(int i=0;i<lft.size();++i)res[lft[i]]=i%k+1;
	for(auto v:res)cout<<v<<" ";cout<<"\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
	cin>>tc;
	while(tc--)ProGamerMove();
}