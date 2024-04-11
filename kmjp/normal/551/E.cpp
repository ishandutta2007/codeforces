#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N,Q;
ll A[505050];
const int DI=770;
ll pl[DI];
vector<pair<ll,int> > M[DI],M2[DI];

void rebuild(int id) {
	M[id].clear();
	M2[id].clear();
	
	for(int i=id*DI;i<(id+1)*DI && i<N;i++) {
		A[i]+=pl[id];
		M[id].push_back(make_pair(A[i],i));
		M2[id].push_back(make_pair(A[i],-i));
	}
	sort(ALL(M[id]));
	sort(ALL(M2[id]));
	pl[id]=0;
}

int getmi(ll V) {
	int i;
	FOR(i,DI) {
		ll t=V-pl[i];
		auto it=lower_bound(ALL(M[i]),make_pair(t,0));
		if(it==M[i].end()) continue;
		if(it->first!=t) continue;
		return it->second;
	}
	return -1;
}

int getma(ll V) {
	int i;
	for(i=DI-1;i>=0;i--) {
		ll t=V-pl[i];
		auto it=lower_bound(ALL(M2[i]),make_pair(t,-10000000));
		if(it==M2[i].end()) continue;
		if(it->first!=t) continue;
		return -it->second;
	}
	return -1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	MINUS(A);
	FOR(i,N) cin>>A[i];
	FOR(i,DI) rebuild(i);
	
	
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>l>>r>>x;
			l--;r--;
			
			if(l/DI==r/DI) {
				for(i=l;i<=r;i++) A[i]+=x;
				rebuild(l/DI);
			}
			else {
				int up=0;
				i=l/DI+1;
				while(l/DI!=i) A[l++]+=x, up++;
				if(up) rebuild(l/DI-1);
				while(l+DI<r) pl[l/DI]+=x, l+=DI;
				up=0;
				for(;l<=r;l++) A[l]+=x,up;
				rebuild(r/DI);
			}
		}
		else {
			cin>>y;
			int mi=getmi(y),ma=getma(y);
			if(mi<0) _P("%d\n",-1);
			else _P("%d\n",ma-mi);
			
		}
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}