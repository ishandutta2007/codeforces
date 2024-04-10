#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>pii;
typedef long long ll;
vector<pii>ans;
void addr(int x,int y){
	ans.push_back({x+1,y});
	ans.push_back({x+2,y});
	ans.push_back({x+2,y+1});
	ans.push_back({x+2,y+2});
	ans.push_back({x+1,y+2});
	ans.push_back({x,y+2});
	ans.push_back({x,y+1});
}
void addl(int x,int y){
	ans.push_back({x-1,y});
	ans.push_back({x-2,y});
	ans.push_back({x-2,y+1});
	ans.push_back({x-2,y+2});
	ans.push_back({x-1,y+2});
	ans.push_back({x,y+2});
	ans.push_back({x,y+1});
}
int main(){
	#ifdef LOCAL_PROJECT
		freopen("input.txt","r",stdin);
		freopen("output.txt","w",stdout);
		freopen("error.txt","w",stderr);
	#else
		cin.tie(0);
		cin.sync_with_stdio(0);
	#endif
	
	int n;
	cin>>n;
	ans.push_back({0,0});
	for(int i=0;i<=n;i++){
		if(i&1)addl(0,2*i);
		else addr(0,2*i);
	}
	printf("%d\n",ans.size());
	for(pii p:ans)printf("%d %d\n",p.first,p.second);
}