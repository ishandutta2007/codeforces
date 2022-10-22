#include<bits/stdc++.h>
#define ll long long
#define fi first
#define se second
#define eb emplace_back
#define pii pair<int,int>
using namespace std;
const int M=1e5+9;
int n,k;
int a[M];
vector<int>g[M];
void work(){
	int ma=0,mi=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;++i)cin>>a[i],mi=min(mi,a[i]);
	for(int i=0;i<=mi;++i)g[i].clear();
	for(int i=1;i<=n;++i)g[a[i]/k].eb(i),ma=max(ma,a[i]/k);
	int ans=ma;
	for(int i=1;i<=mi;++i){
		for(auto o:g[i-1]){
			g[a[o]/(a[o]/i)].eb(o);
			ma=max(ma,a[o]/(a[o]/i));
		}
		g[i-1].clear();
		ans=min(ans,ma-i);
	}
	cout<<ans<<endl;
}
int main(){
	int T;
	cin>>T;
	while(T--)work();
	return 0;
}
/*
	1
	5 2
	4 5 6 8 11
*/