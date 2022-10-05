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
	V operator()(int e) {V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	V add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,18> bt[10][10][4];

string S,T;
int N,Q;

string conv(string s) {
	FORR(c,s) {
		if(c=='A') c=0;
		if(c=='T') c=1;
		if(c=='G') c=2;
		if(c=='C') c=3;
	}
	return s;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	S=conv(S);
	
	FOR(i,N) {
		for(x=1;x<=10;x++) {
			bt[x-1][(i+1)%x][S[i]].add(i+1,1);
		}
	}
	
	cin>>Q;
	while(Q--) {
		cin>>i;
		if(i==1) {
			cin>>i>>T;
			T=conv(T);
			for(x=1;x<=10;x++) {
				bt[x-1][i%x][S[i-1]].add(i,-1);
				bt[x-1][i%x][T[0]].add(i,1);
			}
			S[i-1]=T[0];
		}
		else {
			int L,R;
			cin>>L>>R>>T;
			T=conv(T);
			int ret=0;
			FOR(x,T.size()) {
				ret += bt[T.size()-1][(L+x)%T.size()][T[x]](R)-bt[T.size()-1][(L+x)%T.size()][T[x]](L-1);
			}
			
			cout<<ret<<endl;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}