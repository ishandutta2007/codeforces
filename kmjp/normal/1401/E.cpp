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
int L[1010101],R[1010101],D[1010101],U[1010101];
vector<int> LRdel[1010101],LRadd[1010101],UDdel[1010101],UDadd[1010101];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> bt;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	MINUS(L);
	MINUS(R);
	MINUS(U);
	MINUS(D);
	
	L[0]=L[1000000]=D[0]=D[1000000]=0;
	R[0]=R[1000000]=U[0]=U[1000000]=1000000;
	LRadd[0].push_back(0);
	LRadd[0].push_back(1000000);
	LRdel[1000000].push_back(0);
	LRdel[1000000].push_back(1000000);
	UDadd[0].push_back(0);
	UDadd[0].push_back(1000000);
	UDdel[1000000].push_back(0);
	UDdel[1000000].push_back(1000000);
	
	FOR(i,N) {
		cin>>y>>l>>r;
		LRadd[l].push_back(y);
		LRdel[r].push_back(y);
		L[y]=l;
		R[y]=r;
	}
	FOR(i,M) {
		cin>>x>>l>>r;
		UDadd[l].push_back(x);
		UDdel[r].push_back(x);
		D[x]=l;
		U[x]=r;
	}
	
	ll NE=0,NV=0;
	for(x=0;x<=1000000;x++) {
		FORR(y,LRadd[x]) bt.add(y,1);
		
		if(D[x]==0&&U[x]==1000000) {
			NE+=bt(1000000)-1;
			NV+=bt(1000000);
		}
		else if(D[x]==0) {
			i=bt(U[x]);
			if(bt(U[x])==bt(U[x]-1)) {
				NE+=i;
				NV+=i+1;
			}
			else {
				NE+=i-1;
				NV+=i;
			}
		}
		else if(U[x]==1000000) {
			i=bt(U[x])-bt(D[x]-1);
			if(bt(D[x])==bt(D[x]-1)) {
				NE+=i;
				NV+=i+1;
			}
			else {
				NE+=i-1;
				NV+=i;
			}
		}
		
		FORR(y,LRdel[x]) bt.add(y,-1);
	}
	for(y=0;y<=1000000;y++) {
		FORR(x,UDadd[y]) bt.add(x,1);
		
		if(L[y]==0&&R[y]==1000000) {
			NE+=bt(1000000)-1;
		}
		else if(L[y]==0) {
			i=bt(R[y]);
			if(bt(R[y])==bt(R[y]-1)) {
				NE+=i;
				NV++;
			}
			else {
				NE+=i-1;
			}
		}
		else if(R[y]==1000000) {
			i=bt(R[y])-bt(L[y]-1);
			if(bt(L[y])==bt(L[y]-1)) {
				NE+=i;
				NV++;
			}
			else {
				NE+=i-1;
			}
			
		}
		FORR(x,UDdel[y]) bt.add(x,-1);
	}
	
	cout<<NE-NV+1<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}