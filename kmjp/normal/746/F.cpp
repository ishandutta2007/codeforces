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

int N,W,K;
ll A[202020];
ll T[202020];
ll SA[202020];
int type[202020];
set<pair<int,int>> H,F;
ll TT;

void add(int id) {
	type[id]=1;
	TT+=(T[id]+1)/2;
	H.insert({T[id],id});
	
	if(H.size()>W) {
		auto h=*H.begin();
		H.erase(h);
		TT-=(h.first+1)/2;
		
		type[h.second]=0;
		TT+=h.first;
		F.insert(h);
	}
	
}

void del(int id) {
	if(type[id]==0) {
		TT-=T[id];
		F.erase({T[id],id});
	}
	else {
		TT-=(T[id]+1)/2;
		H.erase({T[id],id});
		if(F.size()) {
			auto f=*F.rbegin();
			F.erase(f);
			TT-=f.first;
			type[f.second]=1;
			TT+=(f.first+1)/2;
			H.insert(f);
		}
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>W>>K;
	FOR(i,N) {
		cin>>A[i];
		SA[i+1]=SA[i]+A[i];
	}
	FOR(i,N) cin>>T[i];
	ll ma=0;
	int L,R=0;
	
	FOR(L,N) {
		while(R<N) {
			add(R);
			if(TT>K) {
				del(R);
				break;
			}
			R++;
		}
		ma=max(ma,SA[R]-SA[L]);
		del(L);
	}
	cout<<ma<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}