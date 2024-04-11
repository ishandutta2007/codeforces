#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N;
ll K,A[303030];
map<int,int> M;


struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,ll val,int pos=29) {
		v += 1;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	int pick(ll val,int pos=29) { // sum [0,s-1]
		if(pos<0) return 0;
		
		int tar=0;
		if(val&(1LL<<pos)) {
			if(nex[0]&&nex[0]->v) tar=0;
			else tar=1;
		}
		else {
			if(nex[1]&&nex[1]->v) tar=1;
			else tar=0;
		}
		return (tar<<pos)+nex[tar]->pick(val,pos-1);
	}
};



vector<int> ret;

void dfs(vector<int> C,int d) {
	if(C.size()<=1) {
		FORR(c,C) ret.push_back(c);
		return;
	}
	vector<int> A[2];
	FORR(c,C) A[(c>>d)%2].push_back(c);
	if((K&(1<<d))==0) {
		dfs(A[0],d-1);
		dfs(A[1],d-1);
		return;
	}
	
	if(A[0].size()&&A[1].size()) {
		BinarySumTrie root;
		FORR(a,A[0]) root.add(a,1);
		FORR(a,A[1]) {
			ll v=root.pick(a);
			if((a^v)>=K) {
				ret.push_back(a);
				ret.push_back(v);
				return;
			}
		}
	}
	
	if(A[0].size()) {
		ret.push_back(A[0][0]);
	}
	else if(A[1].size()) {
		ret.push_back(A[1][0]);
	}
	
	return;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>A[i];
		M[A[i]]=i+1;
	}
	
	if(K==0) {
		cout<<N<<endl;
		FOR(i,N) cout<<(i+1)<<" ";
		cout<<endl;
		return;
	}
	
	vector<int> C;
	FORR2(a,b,M) C.push_back(a);
	
	dfs(C,29);
	if(ret.size()<2) {
		cout<<-1<<endl;
	}
	else {
		cout<<ret.size()<<endl;
		FORR(a,ret) cout<<M[a]<<" ";
		cout<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}