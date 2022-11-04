#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	string s;cin>>s;
	int n=s.size();
	vector<int>v(n);
	for(int i=0;i<n;++i)v[i]=s[i]-'a';
	vector<vector<ll>>cnts(26,vector<ll>(26));
	vector<vector<int>>suf(n+1,vector<int>(26));
	for(int i=n-1;i>=0;--i)
		for(int j=0;j<26;++j){
			suf[i][j]=suf[i+1][j]+(v[i]==j);
			cnts[v[i]][j]+=suf[i+1][j];
		}
	ll res=*max_element(suf[0].begin(),suf[0].end());
	for(int i=0;i<26;++i)res=max(res,*max_element(cnts[i].begin(),cnts[i].end()));
	cout<<res<<endl;
}