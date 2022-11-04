#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=100100,inf=10*N;
map<int,int>dp[N];
map<int,pair<int,char>>prv[N]; // pmul
int a[N];
int n;

string mxx(vector<int>&a){
	int n=a.size();
	string res(n-1,'*');
	for(int i=0;i<n;++i)if(a[i]==1)res[i]='+';
	else break;
	for(int i=n-1;i>0;--i)if(a[i]==1)res[i-1]='+';
	else break;
	return res;
}

string solvedp(vector<int>a){
	if(a.empty())return "";
	int n=a.size();
	for(int i=0;i<=n;++i)dp[i].clear();
	for(int i=0;i<=n;++i)prv[i].clear();
	dp[0][0]=0;
	for(int i=0;i<n;++i)
		for(auto it:dp[i]){
			if(it.first>=inf)return mxx(a)+"+";
			if(!dp[i+1].count(it.first*a[i])||dp[i+1][it.first*a[i]]<it.second){
				dp[i+1][it.first*a[i]]=it.second;
				prv[i+1][it.first*a[i]]={it.first,'*'};
			}
			if(!dp[i+1].count(a[i])||dp[i+1][a[i]]<it.first+it.second){
				dp[i+1][a[i]]=it.first+it.second;
				prv[i+1][a[i]]={it.first,'+'};
			}
		}
	string res;
	int mx=0,mxmul=0;
	for(auto it:dp[n])if(it.first+it.second>mx){
		mx=it.first+it.second;mxmul=it.first;
	}
	for(int i=n;i>1;--i){
		assert(prv[i].count(mxmul));
		res+=prv[i][mxmul].second;
		mxmul=prv[i][mxmul].first;
	}
	reverse(res.begin(),res.end());
	assert(res.size()==a.size()-1);
	return res+"+";
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	int n;cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	string s;cin>>s;
	set<char>chars;
	for(auto c:s)chars.insert(c);
	string res;
	if(chars.count('*')&&chars.count('+')){
		vector<int>aa;
		for(int i=0;i<n;++i){
			if(a[i]==0){
				res+=solvedp(aa)+(i<n-1?"+":"");
				aa.clear();
			}
			else aa.push_back(a[i]);
		}
		if(aa.size()){
			res+=solvedp(aa);
			res.pop_back();
		}
		assert(res.size()==n-1);
	}
	else if(chars.count('+')){
		res=string(n-1,'+');
	}
	else if(chars.count('*')){
		if(chars.count('-')){
			for(int i=0;i<n-1;++i)
				if(a[i+1])res+='*';
				else res+='-';
		}
		else res=string(n-1,'*');
	}
	else if(chars.count('-')){
		res=string(n-1,'-');
	}
	else assert(0);
	cout<<a[0];
	for(int i=1;i<n;++i)cout<<res[i-1]<<a[i];
	cout<<endl;
}