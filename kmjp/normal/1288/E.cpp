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

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,22> bt;

int N,M;
int A[303030];
int ret[303030];
int pos[303030];
int mi[303030],ma[303030];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	for(i=1;i<=N;i++) {
		pos[i]=(1<<20)+i;
		mi[i]=ma[i]=i;
		bt.add(pos[i],1);
	}
	FOR(i,M) {
		cin>>x;
		mi[x]=1;
		ma[x]=max(ma[x],bt(pos[x]));
		bt.add(pos[x],-1);
		pos[x]=(1<<20)-i;
		bt.add(pos[x],1);
	}
	for(i=1;i<=N;i++) {
		ma[i]=max(ma[i],bt(pos[i]));
		cout<<mi[i]<<" "<<ma[i]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}