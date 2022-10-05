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

int T;
int N;
int A[2050];
int R[2050];
vector<int> ret;
int ON;

void debug() {
	int i;
	FOR(i,ON) cerr<<A[i];
	cerr<<endl;
}
void go(int id) {
	ret.push_back(id+1);
	reverse(A,A+id+1);
	int i;
	FOR(i,id+1) R[A[i]]=i;
	//debug();
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ON=N;
		int ng=0;
		FOR(i,N) {
			cin>>A[i];
			A[i]--;
			if(A[i]%2!=i%2) ng=1;
			R[A[i]]=i;
		}
		if(ng==1) {
			cout<<-1<<endl;
			continue;
		}
		
		ret.clear();
		
		while(N>1) {
			if(A[N-1]!=N-1||A[N-2]!=N-2) {
				go(R[N-1]);
				go(R[N-2]-1);
				go(R[N-2]+1);
				go(R[N-1]);
				go(N-1);
			}
			N-=2;
		}
		
		
		FOR(i,ON) assert(A[i]==i);
		cout<<ret.size()<<endl;
		FORR(v,ret) cout<<v<<" ";
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}