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

int N;
int A[303030],P[303030];

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,ll val,int pos=29) {
		v += val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	int pick(ll val,int pos=29) { // sum [0,s-1]
		v--;
		if(pos<0) return 0;
		
		int tar=0;
		if(val&(1LL<<pos)) {
			if(nex[1]&&nex[1]->v) tar=1;
			else tar=0;
		}
		else {
			if(nex[0]&&nex[0]->v) tar=0;
			else tar=1;
		}
		return (tar<<pos)+nex[tar]->pick(val,pos-1);
	}
};

BinarySumTrie root;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	FOR(i,N) scanf("%d",&A[i]);
	FOR(i,N) {
		scanf("%d",&x);
		root.add(x,1);
	}
	
	FOR(i,N) _P("%d ",root.pick(A[i])^A[i]);
	_P("\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}