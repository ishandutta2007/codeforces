#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

class AreaRect { //(0,0)-(X,Y)
	map<ll,ll> M;
public:
	ll sum;
	AreaRect() {
		M[0]=1LL<<60;
		M[1LL<<60]=0;
		sum=0;
	}
	void add(ll x,ll y) {
		auto k=M.lower_bound(x);
		if(k->second>=y) return;
		while(prev(M.lower_bound(x))->second<=y) {
			auto p=*prev(M.lower_bound(x));
			M.erase(p.first);
			sum-=(p.first-prev(M.lower_bound(p.first))->first)*(p.second-M.lower_bound(p.first)->second);
		}
		sum += (x-prev(M.lower_bound(x))->first)*(y-M.lower_bound(x)->second);
		M[x]=y;
	}
};

int N,AA,BB,CC;
vector<pair<int,int>> add[505050];
AreaRect AR;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>AA>>BB>>CC;
	FOR(i,N) {
		int a,b,c;
		cin>>a>>b>>c;
		add[AA].push_back({b,c});
		add[a].push_back({BB,c});
		add[a].push_back({b,CC});
	}
	
	ll ret=0;
	for(x=AA;x>=1;x--) {
		FORR(e,add[x]) AR.add(e.first,e.second);
		ret += 1LL*BB*CC-AR.sum;
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}