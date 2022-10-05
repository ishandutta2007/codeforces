#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
ll X[1010],Y[1010];
map<ll,vector<pair<ll,int>>> V,H;

template<int um> class UF {
	public:
	vector<int> par,rank,cnt;
	UF() {par=rank=vector<int>(um,0); cnt=vector<int>(um,1); for(int i=0;i<um;i++) par[i]=i;}
	void reinit() {int i; FOR(i,um) rank[i]=0,cnt[i]=1,par[i]=i;}
	int operator[](int x) {return (par[x]==x)?(x):(par[x] = operator[](par[x]));}
	int count(int x) { return cnt[operator[](x)];}
	int operator()(int x,int y) {
		if((x=operator[](x))==(y=operator[](y))) return x;
		cnt[y]=cnt[x]=cnt[x]+cnt[y];
		if(rank[x]>rank[y]) return par[x]=y;
		rank[x]+=rank[x]==rank[y]; return par[y]=x;
	}
};

int ok(ll T) {
	UF<1010> uf;
	int i;
	int num=0;

	FORR(v,V) {
		FOR(i,v.second.size()-1) if(v.second[i+1].first-v.second[i].first<=T) uf(v.second[i].second,v.second[i+1].second);
	}
	FORR(h,H) {
		FOR(i,h.second.size()-1) if(h.second[i+1].first-h.second[i].first<=T) uf(h.second[i].second,h.second[i+1].second);
	}
	FOR(i,N) if(uf[i]==i) num++;
	if(num==1) return 1;
	if(num>4) return 0;
	
	int x,y;
	FOR(y,N) FOR(x,y) if(uf[x]!=uf[y]) {
		if(X[x]==X[y]) {
			if(abs(Y[y]-Y[x])<=2*T&&num==2) return 1;
		}
		else if(Y[x]==Y[y]) {
			if(abs(X[y]-X[x])<=2*T&&num==2) return 1;
		}
		else if(abs(X[x]-X[y])<=T&&abs(Y[x]-Y[y])<=T) {
			vector<pair<ll,ll>> P={{X[x],Y[y]},{X[y],Y[x]}};
			FORR(p,P) {
				set<int> S;
				S.insert(uf[x]);
				S.insert(uf[y]);
				ll cx=p.first;
				ll cy=p.second;
				auto it=lower_bound(ALL(V[cx]),make_pair(cy,-1));
				if(it->second>=0 && it->first-cy<=T) S.insert(uf[it->second]);
				it--;
				if(it->second>=0 && cy-it->first<=T) S.insert(uf[it->second]);
				it=lower_bound(ALL(H[cy]),make_pair(cx,-1));
				if(it->second>=0 && it->first-cx<=T) S.insert(uf[it->second]);
				it--;
				if(it->second>=0 && cx-it->first<=T) S.insert(uf[it->second]);
				/*
				FORR(s,S) cout<<s<<" ";
				cout<<endl;
				cout<<T<<" "<<cx<<" "<<cy<<" "<<S.size()<<" "<<num<<endl;
				*/
				if(S.size()==num) return 1;
			}
			
		}
	}
	return 0;
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		V[X[i]].push_back({Y[i],i});
		H[Y[i]].push_back({X[i],i});
	}
	FORR(h,H) {
		h.second.push_back({-1LL<<40,-1});
		h.second.push_back({1LL<<40,-1});
		sort(ALL(h.second));
	}
	FORR(h,V) {
		h.second.push_back({-1LL<<40,-1});
		h.second.push_back({1LL<<40,-1});
		sort(ALL(h.second));
	}
	
	ll T=2000000000LL;
	if(ok(T)==0) return _P("-1\n");
	for(i=30;i>=0;i--) if(T>1<<i && ok(T-(1<<i))) T-=1<<i;
	cout<<T<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}