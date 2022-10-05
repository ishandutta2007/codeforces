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

int T,N;
string S;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>S;
		N=S.size();
		map<char,int> M;
		FORR(c,S) M[c]++;
		vector<char> C;
		FORR(m,M) C.push_back(m.first);
		
		if(M.size()==2) {
			if(C[0]+1==C[1]) {
				cout<<"No answer"<<endl;
				continue;
			}
		}
		if(M.size()==3) {
			if(C[0]+1==C[1]&&C[1]+1==C[2]) {
				cout<<"No answer"<<endl;
				continue;
			}
			if(C[0]+1==C[1]) {
				x=M[C[0]]; while(x--) cout<<C[0];
				x=M[C[2]]; while(x--) cout<<C[2];
				x=M[C[1]]; while(x--) cout<<C[1];
			}
			else {
				x=M[C[1]]; while(x--) cout<<C[1];
				x=M[C[0]]; while(x--) cout<<C[0];
				x=M[C[2]]; while(x--) cout<<C[2];
			}
			cout<<endl;
			continue;
		}
		if(M.size()==4) {
			x=M[C[1]]; while(x--) cout<<C[1];
			x=M[C[3]]; while(x--) cout<<C[3];
			x=M[C[0]]; while(x--) cout<<C[0];
			x=M[C[2]]; while(x--) cout<<C[2];
			cout<<endl;
			continue;
		}
		
		if(C.size()%2==0) {
			
			FOR(i,C.size()/2) {
				x=M[C[i*2]];
				while(x--) cout<<C[i*2];
			}
			FOR(i,C.size()/2) {
				x=M[C[i*2+1]];
				while(x--) cout<<C[i*2+1];
			}
		}
		else {
			
			FOR(i,C.size()/2+1) {
				x=M[C[i*2]];
				while(x--) cout<<C[i*2];
			}
			FOR(i,C.size()/2) {
				x=M[C[i*2+1]];
				while(x--) cout<<C[i*2+1];
			}
		}
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}