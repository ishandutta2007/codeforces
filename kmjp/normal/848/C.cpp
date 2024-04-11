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

int N,M;
int A[101010];
int pre[101010],nex[101010];
set<int> P[101010];

const int DI=400;
vector<pair<int,int>> V[DI];
vector<ll> VV[DI];

void fix(int id) {
	V[id].clear();
	int i;
	FOR(i,DI) {
		int x=id*DI+i;
		if(x>=N) break;
		V[id].push_back({nex[x],x});
	}
	sort(ALL(V[id]));
	ll x=0;
	VV[id].clear();
	VV[id].push_back(0);
	FORR(r,V[id]) VV[id].push_back(VV[id].back()+r.first-r.second);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(pre);
	FOR(i,N) {
		cin>>x;
		A[i]=x;
		if(P[x].size()) {
			y=*P[x].rbegin();
			nex[y]=i;
			pre[i]=y;
		}
		P[x].insert(i);
		nex[i]=N;
	}
	
	
	FOR(i,DI) fix(i);
	
	while(M--) {
		int L,R;
		cin>>i>>L>>R;
		L--;
		if(i==1) {
			if(A[L]==R) continue;
			x=pre[L];
			y=nex[L];
			P[A[L]].erase(L);
			if(x>=0) nex[x]=y;
			if(y<N) pre[y]=x;
			if(x>=0) fix(x/DI);
			
			A[L]=R;
			auto it=P[R].insert(L).first;
			pre[L]=-1;
			nex[L]=N;
			auto it2=it;
			it2++;
			if(it2!=P[R].end()) {
				nex[L]=*it2;
				pre[nex[L]]=L;
			}
			if(it!=P[R].begin()) {
				it--;
				pre[L]=*it;
				nex[pre[L]]=L;
				fix(pre[L]/DI);
			}
			
			fix(L/DI);
		}
		else {
			
			ll ret=0;
			while(L%DI && L<R) {
				if(nex[L]<R) ret+=nex[L]-L;
				L++;
			}
			y=R;
			while(y%DI && L<y) {
				y--;
				if(nex[y]<R) ret+=nex[y]-y;
			}
			for(;L+DI<=R;L+=DI) {
				y=L/DI;
				x=lower_bound(ALL(V[y]),make_pair(R,0))-V[y].begin();
				ret+=VV[y][x];
			}
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}