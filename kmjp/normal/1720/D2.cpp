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

struct BinarySumTrie {
	BinarySumTrie *nex[2];
	ll v[2];
	BinarySumTrie() {
		nex[0]=nex[1]=NULL;
		v[0]=v[1]=0;
	}
	void add(ll s,ll t,ll val,int pos=30) {
		v[(t>>(pos+1))&1]=max(v[(t>>(pos+1))&1],val);
		if(pos>=0) {
			int c=((s^t)>>pos)&1;
			if(!nex[c]) nex[c]=new BinarySumTrie();
			nex[c]->add(s,t,val,pos-1);
		}
	}
	ll get(ll s,ll t,int pos) { // sum [0,s-1]
		if(pos<0) return 0;
		int x=(s>>pos)&1;
		int y=(t>>pos)&1;
		ll ret=0;
		if(nex[x^y]) ret=max(ret,nex[x^y]->get(s,t,pos-1));
		if(x==0&&y==0&&nex[x^y^1]) ret=max(ret,nex[x^y^1]->v[1]);
		if(x==0&&y==1&&nex[x^y^1]) ret=max(ret,nex[x^y^1]->v[1]);
		if(x==1&&y==0&&nex[x^y^1]) ret=max(ret,nex[x^y^1]->v[0]);
		if(x==1&&y==1&&nex[x^y^1]) ret=max(ret,nex[x^y^1]->v[0]);
		
		return ret;
	}
};


int T,N,A[303030];
int dp[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		BinarySumTrie root;
		cin>>N;
		
		int ma=0;
		FOR(i,N) {
			cin>>A[i];
			dp[i]=1+root.get(A[i],i,30);
			ma=max(ma,dp[i]);
			root.add(A[i],i,dp[i]);
		}
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}