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
int T,K,X;

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v;
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;v=0;
	}
	void add(ll s,ll val,int pos=31) {
		v += val;
		if(pos>=0) {
			int c=(s>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,val,pos-1);
		}
	}
	ll get(ll s,int pos=31) { // sum [0,s-1]
		if(pos<0) return 0;
		int c=(s>>pos)&1;
		if(c) return (nex[0]?nex[0]->v:0)+(nex[1]?nex[1]->get(s,pos-1):0);
		else return (nex[0]?nex[0]->get(s,pos-1):0);
	}
};
BinarySumTrie bst;
int add;

ll mapto(ll start) {
	return start+add-bst.get(start+1);
}

ll getcur(ll base) {
	//base
	ll cur=-1;
	int i;
	for(i=30;i>=0;i--) {
		if(mapto(cur+(1<<i))<base) cur+=1<<i;
	}
	return cur+1;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int ret=0;
	FOR(i,N) {
		cin>>T>>K;
		T+=1000000;
		ll a=getcur(T);
		ll b=getcur(T+1);
		add++;
		bst.add(a,1);
		bst.add(b,1);
		
		while(K--) {
			cin>>X;
			X=(X+ret)%(1000000001);
			X+=1000000;
			ret=mapto(X)-(1000000);
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