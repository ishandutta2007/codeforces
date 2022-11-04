#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=1010,mod[3]={int(1e9+7),998244353,int(1e9+7)},mul=29;
string d[N];
vector<int>hsh[2][N];
int ways[N];

int powmod(ll a,ll b,ll m){
	if(!b)return 1;
	if(b&1)return powmod(a*a%m,b/2,m)*a%m;
	return powmod(a*a%m,b/2,m);
}

int inv(ll a,ll m){
	return powmod(a,m-2,m);
}

int n,mulinv[2]={inv(mul,mod[0]),inv(mul,mod[1])};

pair<int,int>geth(pair<int,int>str,int pref){
	if(str.second>=pref)return {hsh[0][str.first][pref],hsh[1][str.first][pref]};
	return {(ll(mod[0]+hsh[0][str.first][pref+1]-hsh[0][str.first][str.second+1])*mulinv[0]
					+hsh[0][str.first][str.second])%mod[0],
					(ll(mod[1]+hsh[1][str.first][pref+1]-hsh[1][str.first][str.second+1])*mulinv[1]
					+hsh[1][str.first][str.second])%mod[1]};
}


signed main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>d[i];
	for(int k=0;k<2;++k)
		for(int i=0;i<n;++i){
			hsh[k][i].resize(d[i].size()+2);
			for(int j=1,m=1;j<hsh[k][i].size();++j,m=ll(m)*mul%mod[k])
				hsh[k][i][j]=(ll(j-1<d[i].size()?d[i][j-1]-'a'+1:0)*m+hsh[k][i][j-1])%mod[k];
		}
	vector<pair<int,int>>strs;
	for(int i=0;i<n;++i)
		for(int j=0;j<=d[i].size();++j)
			strs.push_back({i,j});
	auto cmp=[&](const pair<int,int>&p,const pair<int,int>&q){
		int sz1=d[p.first].size()-(p.second!=d[p.first].size());
		int sz2=d[q.first].size()-(q.second!=d[q.first].size());
		int l=0,r=min(sz1,sz2);
		while(l<r){
			int m=(l+r)/2;
			if(geth(p,m+1)==geth(q,m+1))l=m+1;
			else r=m;
		}
		if(l==min(sz1,sz2))return sz1<sz2||(sz1==sz2&&p.first<q.first);
		return d[p.first][l+(p.second<=l)]<d[q.first][l+(q.second<=l)];
	};
	sort(strs.begin(),strs.end(),cmp);
	for(auto p:strs)if(!p.first)++ways[p.first];
	else ways[p.first]=(ways[p.first]+ways[p.first-1])%mod[2];
	cout<<ways[n-1]<<endl;
}