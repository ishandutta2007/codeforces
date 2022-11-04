#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define int ll

const int N=100100,M=10000100,mod=1e9+7,logN=log2(N)+3;
int n,q;
int a[N],qa[N];
vector<int>g[N];
unordered_map<int,vector<pair<int,int>>>powers,qpowers; // power, id query/id vertex
int lft[N],rght[N],res[N];
int s[M];
int in[N],out[N]; // euler tour

int idx2lca[N],timer2idx[2*N]; // lca
vector<int>lca;
int timer;

ll powermod(ll a,ll b){
	if(!b)return 1;
	if(b%2)return a*powermod(a*a%mod,b/2)%mod;
	else return powermod(a*a%mod,b/2);
}

struct fenwicktree{
	int fenwick[2*N]={};
	int update(int u,int d){
		++u;
		for(;u<2*N;u+=u&-u)fenwick[u]+=d;
	}
	int query(int u){
		++u;
		int res=0;
		for(;u;u-=u&-u)res+=fenwick[u];
		return res;
	}
};
	

struct sparsetable{
	int mx=lca.size();
	vector<int>table[logN];
	void build(){
		for(int i=0;i<logN;++i)table[i].resize(mx);
		table[0]=lca;
		for(int i=1;i<logN;++i)
			for(int j=0;j+(1<<(i-1))<mx;++j)
				table[i][j]=min(table[i-1][j],table[i-1][j+(1<<(i-1))]);
	}
	int lcaq(int u,int v){
		if(u>=N||v>=N){cout<<"lmao\n";exit(0);}
		int l=idx2lca[u],r=idx2lca[v];
		if(r-l+1<=0){cout<<"wtf\n";exit(0);}
		int i=log2(r-l+1);
		if(i>=logN){cout<<i<<" aha\n";exit(0);}
		if(r-((1<<i)-1)>=lca.size()){cout<<"k\n";exit(0);}
		if(min(table[i][l],table[i][r-((1<<i)-1)])>=2*N){cout<<"noway\n";exit(0);}
		return timer2idx[min(table[i][l],table[i][r-((1<<i)-1)])];
	}
};
	

// in-order for euler tour, weird-order for lca
void go(int idx,int par){
	timer2idx[timer]=idx;
	idx2lca[idx]=lca.size();
	int minetimer=timer;
	lca.push_back(minetimer);
	in[idx]=timer++;
	for(auto v:g[idx])if(v!=par){
		go(v,idx);
		lca.push_back(minetimer);
	}
	if(g[idx].size()==1-!idx)lca.push_back(minetimer);
	out[idx]=timer++;
}

void sieve(){
	s[1]=1;
	for(int i=2;i<M;++i)
		if(!s[i]){
			s[i]=i;
			for(ll j=(ll)i*i;j<M;j+=i)
				if(!s[j])s[j]=i;
		}
}

void factorize(int num,int id,bool q){
	while(num!=1){
		int p=s[num];
		int cnt=1;
		while(s[num/p]==p){++cnt;num/=p;}
		num/=p;
		if(q)qpowers[p].push_back({cnt,id});
		else powers[p].push_back({cnt,id});
	}
}

main(){
	cin.tie(0);cin.sync_with_stdio(0);
	cin>>n;
	for(int i=0;i<n-1;++i){
		int u,v;cin>>u>>v;--u;--v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=0;i<n;++i)cin>>a[i];
	cin>>q;
	for(int i=0;i<q;++i)cin>>lft[i]>>rght[i]>>qa[i];
	for(int i=0;i<q;++i){--lft[i];--rght[i];}
	for(int i=0;i<q;++i)res[i]=1;
	sieve();
	for(int i=0;i<n;++i)factorize(a[i],i,false);
	for(int i=0;i<q;++i)factorize(qa[i],i,true);
	for(auto it=powers.begin();it!=powers.end();++it)sort(it->second.begin(),it->second.end());
	for(auto it=qpowers.begin();it!=qpowers.end();++it)sort(it->second.begin(),it->second.end());
	go(0,0);
	sparsetable st;st.build();
	fenwicktree ft;
	for(auto it=qpowers.begin();it!=qpowers.end();++it){
		int i=it->first;
		int qidx=0,aidx=0,lastval=0;
		while(qidx<qpowers[i].size()){
			while(aidx<powers[i].size()&&powers[i][aidx].first<=qpowers[i][qidx].first){
				int u=powers[i][aidx].second,val=powers[i][aidx].first-lastval;
				ft.update(in[u],val);
				ft.update(out[u],-val);
				++aidx;
			}
			for(int j=aidx;j<powers[i].size();++j){
				int u=powers[i][j].second,val=qpowers[i][qidx].first-lastval;
				ft.update(in[u],val);
				ft.update(out[u],-val);
			}
			lastval=qpowers[i][qidx].first;
			while(qidx<qpowers[i].size()&&qpowers[i][qidx].first==lastval){
				int queryidx=qpowers[i][qidx].second;
				int u=lft[queryidx],v=rght[queryidx];
				if(in[u]>in[v])swap(u,v);
				int lcauv=st.lcaq(u,v);
				int first=ft.query(in[u])-ft.query(in[lcauv]),second=ft.query(in[v])-ft.query(in[lcauv]-1);
				res[queryidx]=(ll)res[queryidx]*powermod(i,first+second)%mod;
				++qidx;
			}
		}
		for(int j=0;j<powers[i].size();++j){
			int u=powers[i][j].second,val=min(lastval,powers[i][j].first);
			ft.update(in[u],-val);
			ft.update(out[u],val);
		}
	}
	for(int i=0;i<q;++i)cout<<res[i]<<" ";cout<<endl;
}