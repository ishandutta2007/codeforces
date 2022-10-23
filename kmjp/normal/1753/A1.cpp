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

int T,N,A[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		vector<int> V;
		FOR(i,N) {
			cin>>A[i];
			if(A[i]) V.push_back(i);
		}
		vector<pair<int,int>> C;
		if(V.empty()) {
			cout<<1<<endl;
			cout<<1<<" "<<N<<endl;
		}
		else if(V.size()%2) {
			cout<<-1<<endl;
		}
		else {
			if(V[0]) C.push_back({0,V[0]-1});
			if(V.back()<N-1) C.push_back({V.back()+1,N-1});
			
			FOR(i,V.size()/2) {
				x=V[i*2];
				y=V[i*2+1];
				if((x%2==y%2)==(A[x]==A[y])) {
					C.push_back({x,x});
					C.push_back({x+1,y});
				}
				else {
					C.push_back({x,y});
				}
				if(i&&V[i*2-1]+1!=V[i*2]) C.push_back({V[i*2-1]+1,V[i*2]-1});
			}
			
			sort(ALL(C));
			cout<<C.size()<<endl;
			FORR2(a,b,C) cout<<a+1<<" "<<b+1<<endl;
		}
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}