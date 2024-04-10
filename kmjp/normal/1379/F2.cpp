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

const int NV=1<<20;
int A[NV*2],B[NV*2],C[NV*2];

int N,M,Q;
multiset<int> L[202020],R[202020];
set<pair<int,int>> P;

void update(int entry) {
	entry += NV;
	if(L[entry-NV].empty()) {
		A[entry]=1<<20;
	}
	else {
		A[entry]=*L[entry-NV].begin();
	}
	if(R[entry-NV].empty()) {
		B[entry]=-1;
	}
	else {
		B[entry]=*prev(R[entry-NV].end());
	}
	C[entry]=A[entry]<=B[entry];
	
	while(entry>1) {
		entry>>=1;
		C[entry]=C[entry*2] | C[entry*2+1] | (A[entry*2]<=B[entry*2+1]);
		A[entry]=min(A[entry*2],A[entry*2+1]);
		B[entry]=max(B[entry*2],B[entry*2+1]);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>Q;
	
	FOR(i,2*NV) {
		A[i]=1<<20;
		B[i]=-1;
		C[i]=0;
	}
	
	
	int NF=0;
	while(Q--) {
		cin>>y>>x;
		y--;
		x--;
		int r=y%2;
		y/=2;x/=2;
		
		if(P.count({y,r*1000000+x})) {
			P.erase({y,r*1000000+x});
			
			if(r==0) {
				L[x].erase(L[x].find(y));
			}
			else {
				R[x].erase(R[x].find(y));
			}
		}
		else {
			P.insert({y,r*1000000+x});
			if(r==0) {
				L[x].insert(y);
			}
			else {
				R[x].insert(y);
			}
		}
		update(x);
		if(C[1]) {
			cout<<"NO"<<endl;
		}
		else {
			cout<<"YES"<<endl;
		}
		
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}