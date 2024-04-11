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

string S;
string R[2];
int pos[256];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	MINUS(pos);
	cin>>S;
	FOR(i,27) {
		if(pos[S[i]]==-1) pos[S[i]]=i;
		else {
			x = i-pos[S[i]]-1;
			if(x==0) return _P("Impossible\n");
			for(j=0;j<27;j++) {
				if(i==j) continue;
				if(j<=pos[S[i]]+x/2) R[1] += S[j];
				else R[0]=S[j]+R[0];
			}
			
			while(R[0].size()>R[1].size()) {
				R[1]=R[0][0]+R[1];
				R[0]=R[0].substr(1);
			}
			while(R[1].size()>R[0].size()) {
				R[0]=R[1][0]+R[0];
				R[1]=R[1].substr(1);
			}
			cout<<R[0]<<endl;
			cout<<R[1]<<endl;
			break;
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