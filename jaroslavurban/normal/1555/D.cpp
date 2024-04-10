#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove(){
	int n,m;cin>>n>>m;
	string s;cin>>s;
	vector<int>per(3);per[1]=1,per[2]=2;
	vector<vector<int>>cost(6,vector<int>(n+1));
	int c=0;
	do{
		for(int i=0;i<n;++i)cost[c][i+1]=cost[c][i]+(per[i%3]!=s[i]-'a');
		++c;
	}while(next_permutation(per.begin(),per.end()));
	while(m--){
		int l,r;cin>>l>>r;--l;
		int res=INT_MAX;
		for(int i=0;i<6;++i)res=min(res,cost[i][r]-cost[i][l]);
		cout<<res<<"\n";
	}
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout<<setprecision(9)<<fixed;
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}