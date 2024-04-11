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


int N,Q,S;
vector<pair<int,int>> E[1<<20];
ll cost[1<<20];

template<int NV> class SegTree_1 {
public:
	void getval(int x,int y,int V,int dir,int W,int l=0,int r=NV,int k=1) { // x<=i<y
		if(r<=x || y<=l) return;
		if(x<=l && r<=y) {
			if(dir==0) {
				E[V].push_back({W,k});
			}
			else {
				k += (1<<18);
				V += (1<<18);
				E[k].push_back({W,V});
			}
			return;
		}
		
		getval(x,y,V,dir,W,l,(l+r)/2,k*2);
		getval(x,y,V,dir,W,(l+r)/2,r,k*2+1);
	}
};
SegTree_1<1<<17> st[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	
	FOR(i,1<<17) {
		if(i) {
			E[i].push_back({0,2*i});
			E[i].push_back({0,2*i+1});
			E[(1<<18)+2*i].push_back({0,(1<<18)+i});
			E[(1<<18)+2*i+1].push_back({0,(1<<18)+i});
		}
		E[(1<<17)+i].push_back({0,(1<<17)+i+(1<<18)});
		E[(1<<17)+i+(1<<18)].push_back({0,(1<<17)+i});
	}
	while(Q--) {
		int T,V,U,L,R,W;
		cin>>T;
		if(T==1) {
			cin>>V>>U>>W;
			V--,U--;
			E[(1<<17)+V].push_back({W,(1<<17)+U});
		}
		else {
			cin>>V>>L>>R>>W;
			L--,R,V--;
			st[T-2].getval(L,R,(1<<17)+V,T-2,W);
		}
	}
	
	S--;
	FOR(i,1<<20) cost[i]=1LL<<60;
	S += 1<<17;
	cost[S]=0;
	priority_queue<pair<ll,int>> Q;
	Q.push({0,S});
	while(Q.size()) {
		ll co=-Q.top().first;
		int cur=Q.top().second;
		Q.pop();
		if(co!=cost[cur]) continue;
		FORR(e,E[cur]) {
			if(cost[e.second]>co+e.first) {
				cost[e.second] = co+e.first;
				Q.push({-cost[e.second],e.second});
			}
		}
	}
	
	FOR(i,N) {
		if(cost[i+(1<<17)]==1LL<<60) cost[i+(1<<17)]=-1;
		cout<<cost[i+(1<<17)];
		if(i==N-1) cout<<endl;
		else cout<<" ";
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}