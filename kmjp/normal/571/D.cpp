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

template<class V, int ME> class BIT_r {
public:
	V bit[2][1<<ME];
	BIT_r(){clear();};
	void clear() {ZERO(bit);};
	
	void update(int entry, V val0, V val1) {
		entry++;
		while(entry <= 1<<ME) bit[0][entry-1]+=val0, bit[1][entry-1] += val1, entry += entry & -entry;
	}
	V total(int entry) {
		int e=entry++;
		V v0=0,v1=0;
		while(entry>0) v0+=bit[0][entry-1], v1+=bit[1][entry-1], entry -= entry & -entry;
		return e*v0+v1;
	}
	void add(int L, int R, V val) { // add val to L<=x<=R
		update(L,val,-val*(L-1));
		update(R+1,-val,val*R);
	}
};

int N,M;
vector<int> UD[505050];
vector<int> MD[505050];
char C[505050];
int X[505050],Y[505050];
int revUD[505050], revMD[505050];
pair<int,int> UDP[505050],MDP[505050];
pair<int,int> reset[505050];
ll ret[505050];
vector<int> PQ[505050];
BIT_r<ll,23> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) UD[i+1].push_back(i+1),MD[i+1].push_back(i+1);
	
	FOR(i,M) {
		cin>>C[i]>>X[i];
		if(C[i]=='U') {
			cin>>Y[i];
			if(UD[X[i]].size()<UD[Y[i]].size()) {
				UD[Y[i]].insert(UD[Y[i]].end(),UD[X[i]].begin(),UD[X[i]].end());
				swap(UD[X[i]],UD[Y[i]]);
			}
			else {
				UD[X[i]].insert(UD[X[i]].end(),UD[Y[i]].begin(),UD[Y[i]].end());
			}
			UD[Y[i]].clear();
		}
		if(C[i]=='M') {
			cin>>Y[i];
			if(MD[X[i]].size()<MD[Y[i]].size()) {
				MD[Y[i]].insert(MD[Y[i]].end(),MD[X[i]].begin(),MD[X[i]].end());
				swap(MD[X[i]],MD[Y[i]]);
			}
			else {
				MD[X[i]].insert(MD[X[i]].end(),MD[Y[i]].begin(),MD[Y[i]].end());
			}
			MD[Y[i]].clear();
		}
	}
	x=y=0;
	for(i=1;i<=N;i++) FORR(r,UD[i]) revUD[r]=++x;
	for(i=1;i<=N;i++) FORR(r,MD[i]) revMD[r]=++y;
	for(i=1;i<=N;i++) UDP[i]={revUD[i],revUD[i]},MDP[i]={revMD[i],revMD[i]};
	FOR(i,M) {
		if(C[i]=='M') {
			assert(MDP[X[i]].second+1==MDP[Y[i]].first || MDP[Y[i]].second+1==MDP[X[i]].first);
			MDP[X[i]].first=min(MDP[X[i]].first,MDP[Y[i]].first);
			MDP[X[i]].second=max(MDP[X[i]].second,MDP[Y[i]].second);
		}
		if(C[i]=='Z') reset[i]=MDP[X[i]];
	}
	set<pair<int,int> > QE;
	for(i=M-1;i>=0;i--) {
		if(C[i]=='Q') QE.insert({revMD[X[i]],i});
		if(C[i]=='Z') {
			for(auto it=QE.lower_bound({reset[i].first,0}); it!=QE.end() && it->first<=reset[i].second;) {
				PQ[i].push_back(it->second);
				QE.erase(it++);
			}
		}
	}
	FOR(i,M) {
		if(C[i]=='U') {
			assert(UDP[X[i]].second+1==UDP[Y[i]].first || UDP[Y[i]].second+1==UDP[X[i]].first);
			UDP[X[i]].first=min(UDP[X[i]].first,UDP[Y[i]].first);
			UDP[X[i]].second=max(UDP[X[i]].second,UDP[Y[i]].second);
		}
		if(C[i]=='Z') {
			FORR(r,PQ[i]) ret[r]=bt.total(revUD[X[r]])-bt.total(revUD[X[r]]-1);
		}
		if(C[i]=='A') {
			bt.add(UDP[X[i]].first,UDP[X[i]].second,UDP[X[i]].second-UDP[X[i]].first+1);
		}
		if(C[i]=='Q') {
			cout<<bt.total(revUD[X[i]])-bt.total(revUD[X[i]]-1)-ret[i]<<endl;
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