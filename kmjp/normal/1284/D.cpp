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
int S[2][202020],E[2][202020];
vector<int> add[404040],del[404040];

template<class V, int ME> class BIT {
public:
	V bit[1<<ME];
	V operator()(int e) {if(e<0) return 0;V s=0;e++;while(e) s+=bit[e-1],e-=e&-e; return s;}
	void add(int e,V v) { e++; while(e<=1<<ME) bit[e-1]+=v,e+=e&-e;}
};
BIT<int,20> BS,BE;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	vector<int> X;
	X.push_back(0);
	FOR(i,N) {
		cin>>S[0][i]>>E[0][i]>>S[1][i]>>E[1][i];
		E[0][i]++;
		E[1][i]++;
		X.push_back(S[0][i]);
		X.push_back(S[1][i]);
		X.push_back(E[0][i]);
		X.push_back(E[1][i]);
	}
	sort(ALL(X));
	X.erase(unique(ALL(X)),X.end());
	FOR(i,N) {
		S[0][i]=lower_bound(ALL(X),S[0][i])-X.begin();
		E[0][i]=lower_bound(ALL(X),E[0][i])-X.begin();
		S[1][i]=lower_bound(ALL(X),S[1][i])-X.begin();
		E[1][i]=lower_bound(ALL(X),E[1][i])-X.begin();
	}
	FOR(j,2) {
		FOR(i,N) {
			add[S[0][i]].push_back(i);
			del[E[0][i]].push_back(i);
		}
		FOR(i,404040) {
			FORR(e,del[i]) {
				if(BE(S[1][e])) return _P("NO\n");
				if(BS((1<<19)-1)-BS(E[1][e]-1)) return _P("NO\n");
			}
			FORR(e,del[i]) {
				BS.add(S[1][e],-1);
				BE.add(E[1][e],-1);
			}
			FORR(e,add[i]) {
				BS.add(S[1][e],1);
				BE.add(E[1][e],1);
			}
			add[i].clear();
			del[i].clear();
		}
		FOR(i,N) {
			swap(S[0][i],S[1][i]);
			swap(E[0][i],E[1][i]);
		}
	}
	
	cout<<"YES"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}