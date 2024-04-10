#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s;
int n,m;
void Solve(){
	cin>>n;
	cin>>s;
	cin>>m;
	set<char> S;
	for(int i=1;i<=m;++i){
		char c;
		cin>>c;
		S.insert(c);
	}
	int ans=0,now=0;
	for(auto c:s){
		if(S.count(c)){
			ans=max(ans,now);
			now=0;
		}
		++now;
	}
	cout<<ans<<'\n';
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin>>T;
	while(T--)Solve();
	return 0;
}