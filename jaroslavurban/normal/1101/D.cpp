#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
//#define int ll
//#define endl '\n'

// use unique(x) - removec consecutive items, returns vec.begin() + number of items
// for vector: sort(all(vec)); vec.erase(unique(all(vec)), vec.end());
// use iota(all(vec), 0) for filling a vector with 0,1,2...
// use fill(all(vec), 1) for filling a vector with 1,1,1...
// use rotate(vec.begin(), vec.begin() + 1, vec.end()) to rotate a vector | middle arg becomes first
// print number in binary -> cout << bitset<20>(n);

const int N=200010;
int a[N],bst,s[N],n;
vector<int>g[N];
vector<int>sieve(int n){
	if(s[2]){
		vector<int>res;
		while(n!=1){
			res.push_back(s[n]);
			n/=s[n];
		}
		return res;
	}
	for(int i=2;i<N;++i)
		if(!s[i])
			for(int j=i;j<N;j+=i)
				s[j]=i;
	return {};
}
map<int,int>dfs(int u,int p,int d){
	vector<map<int,int>>maps;
	map<int,int>m;
	for(auto v:g[u])if(v!=p)maps.push_back(dfs(v,u,d+1));
	vector<int>primes=sieve(a[u]);
	for(auto pr:primes){
		int b1=-1,b2=-1;
		for(auto mp:maps){
			auto dep=mp.find(pr);
			if(dep==mp.end())continue;
			if(dep->second>b1){
				b2=b1;
				b1=dep->second;
			}
			else if(dep->second>b2)b2=dep->second;
		}
		if(~b1){
			bst=max(bst,b1-d+1);
			m[pr]=b1;
			if(~b2)bst=max(bst,b1+b2-2*d+1);
		}
		else{
			m[pr]=d;
			bst=max(bst,1);
		}
	}
	return m;
}

		

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n;++i)cin>>a[i];
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	sieve(0);
	dfs(0,0,0);
	cout<<bst<<endl;
}