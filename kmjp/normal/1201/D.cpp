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

int H,W,K,Q;
vector<int> X[202020];
set<int> Y;
vector<int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>K>>Q;
	int may=0;
	Y.insert(0);
	FOR(i,K) {
		cin>>y>>x;
		X[y-1].push_back(x-1);
		may=max(may,y-1);
		Y.insert(y-1);
	}
	FOR(i,Q) {
		cin>>x;
		C.push_back(x-1);
	}
	sort(ALL(C));
	
	map<int,ll> V;
	V[0]=0;
	
	FORR(y,Y) {
		if(y==0 && X[0].empty()) {
			V.clear();
			V[C[0]]=C[0];
			continue;
		}
		
		sort(ALL(X[y]));
		int L=X[y][0];
		int R=X[y].back();
		
		
		if(y==*Y.rbegin()) {
			ll mi=1LL<<60;
			FORR(v,V) {
				ll ret=v.second+min(abs(L-v.first),abs(R-v.first))+abs(R-L);
				mi=min(mi,ret);
			}
			cout<<mi+may<<endl;
			return;
		}
		
		map<int,ll> W;
		FORR(v,V) {
			// left
			ll ret=v.second+abs(R-v.first)+abs(L-R);
			x=lower_bound(ALL(C),L)-C.begin();
			
			if(x<Q) {
				if(W.count(C[x])==0) W[C[x]]=1LL<<60;
				W[C[x]]=min(W[C[x]],ret+abs(C[x]-L));
			}
			if(x) {
				x--;
				if(W.count(C[x])==0) W[C[x]]=1LL<<60;
				W[C[x]]=min(W[C[x]],ret+abs(C[x]-L));
			}
			
			// right
			ret=v.second+abs(L-v.first)+abs(L-R);
			x=lower_bound(ALL(C),R)-C.begin();
			if(x<Q) {
				if(W.count(C[x])==0) W[C[x]]=1LL<<60;
				W[C[x]]=min(W[C[x]],ret+abs(C[x]-R));
			}
			if(x) {
				x--;
				if(W.count(C[x])==0) W[C[x]]=1LL<<60;
				W[C[x]]=min(W[C[x]],ret+abs(C[x]-R));
			}
			
		}
		swap(V,W);
		
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}