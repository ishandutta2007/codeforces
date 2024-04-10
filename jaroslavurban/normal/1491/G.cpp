#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
const int N=200100;
int a[N],vis[N];
int n;
vector<int>cyc;
vector<pair<int,int>>res;

void dfs(int idx){
	vis[idx]=true;
	cyc.push_back(idx);
	if(!vis[a[idx]])dfs(a[idx]);
}

int mex(vector<int>&c){
	int cur=0;
	while(cur<c.size()&&c[cur]==cur)++cur;
	return cur;
}

int solve2(vector<int>c1,vector<int>c2);

int solve1(vector<int>c){
	if(c.size()==1)return 1;
	if(c.size()==2)return solve2(c,{mex(c)});
	int n=c.size();
	res.push_back({c[n-2],c[n-1]});
	res.push_back({c[n-3],c[n-1]});
	for(int i=0;i<n-2;++i)res.push_back({c[i],c[n-2]});
	res.push_back({c[n-2],c[n-1]});
	return 1;
}

int solve2(vector<int>c1,vector<int>c2){
	if(c1.size()==1)return solve1(c2);
	for(auto p:c1)res.push_back({p,c2.back()});
	for(auto p:c2)res.push_back({c1[0],p});
	return 1;
}
 
main(){
	cin.tie(0);ios::sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n;++i)--a[i];
	vector<vector<int>>cycles;
	for(int i=0;i<n;++i)if(!vis[i]){
		dfs(i);
		cycles.push_back(cyc);
		cyc.clear();
	}
	for(int i=0;i<cycles.size();i+=2){
		if(i+1<cycles.size())solve2(cycles[i],cycles[i+1]);
		else solve1(cycles[i]);
	}
	cout<<res.size()<<endl;
	for(auto r:res)cout<<r.first+1<<" "<<r.second+1<<endl;
	assert(res.size()<=n+1);
}