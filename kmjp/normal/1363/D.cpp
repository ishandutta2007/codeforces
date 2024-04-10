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

int T;
int N,K;
vector<int> S[1010];
int O[1010];

int ask(vector<int> V) {
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	if(V.empty()) return 0;
	cout<<"? "<<V.size();
	FORR(v,V) cout<<" "<<(v+1);
	cout<<endl;
	int x;
	cin>>x;
	return x;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		MINUS(O);
		FOR(i,K) {
			S[i].clear();
			cin>>x;
			FOR(j,x) {
				cin>>y;
				S[i].push_back(y-1);
				O[y-1]=i;
			}
		}
		
		vector<int> C,ret(K);
		FOR(i,N) C.push_back(i);
		int ma=ask(C);
		C.clear();
		FOR(i,N) if(O[i]==-1) C.push_back(i);
		x=ask(C);
		
		FOR(i,K) ret[i]=ma;
		if(ma!=x) {
			int L=0,R=K;
			while(R-L>1) {
				int M=(L+R)/2;
				C.clear();
				for(i=L;i<M;i++) FORR(s,S[i]) C.push_back(s);
				if(ask(C)==ma) R=M;
				else L=M;
			}
			
			C.clear();
			FOR(i,N) if(O[i]!=L) C.push_back(i);
			ret[L]=ask(C);
			
		}
		
		
		cout<<"!";
		FORR(r,ret) cout<<" "<<r;
		cout<<endl;
		cin>>s;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}