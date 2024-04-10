#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const int N=150100,M=1000100;
int prime[M];
int p[M],a[N];
int n,q;

int getp(int u){return p[u]==u?u:p[u]=getp(p[u]);}
void uni(int u,int v){p[getp(u)]=p[getp(v)];}

void erat(){ // exclusive
	for(int i=2;i<M;++i)if(!prime[i]){
		for(int j=i;j<M;j+=i)prime[j]=i;
	}
}

unordered_map<int,int>factorize(int x){
	unordered_map<int,int>res;
	while(x!=1){
		++res[prime[x]];
		x/=prime[x];
	}
	return res;
}

void ProGamerMove(){
	cin>>n>>q;
	for(int i=0;i<n;++i){
		cin>>a[i];
		auto mp=factorize(a[i]);
		for(auto[u,cnt]:mp)
			for(auto[v,cnt2]:mp)
				uni(u,v);
	}
	set<pair<int,int>>canone;
	for(int i=0;i<n;++i){
		auto fa=factorize(a[i]);
		auto fn=factorize(a[i]+1);
		for(auto[u,cn1]:fa)
			for(auto[v,cn2]:fn)
				if(getp(u)!=getp(v))
					canone.insert({min(getp(u),getp(v)),max(getp(u),getp(v))});
		for(auto[u,cn1]:fn)
			for(auto[v,cn2]:fn)
				if(getp(u)!=getp(v))
					canone.insert({min(getp(u),getp(v)),max(getp(u),getp(v))});
	}
	while(q--){
		int i,j;cin>>i>>j;--i,--j;
		int pi=getp(prime[a[i]]);
		int pj=getp(prime[a[j]]);
		if(pi==pj)cout<<"0\n";
		else if(canone.count({min(pi,pj),max(pi,pj)}))cout<<"1\n";
		else cout<<"2\n";
	}
}

signed main(){
	erat();
	iota(p,p+M,0);
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int tc=1;
//	cin>>tc;
	while(tc--)ProGamerMove();
}