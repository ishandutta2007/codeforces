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


int X[4];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X[0]>>X[1]>>X[2]>>X[3];
	FOR(x,4) {
		int Y[4];
		FOR(i,4) Y[i]=X[i];
		vector<int> C;
		int cur=x;
		while(1) {
			if(Y[cur]==0) break;
			Y[cur]--;
			C.push_back(cur);
			if(cur==0) {
				cur=1;
			}
			else if(cur==3) {
				cur=2;
			}
			else if(cur==1) {
				if(Y[0]) cur=0;
				else cur=2;
			}
			else {
				if(Y[3]) cur=3;
				else cur=1;
			}
		}
		
		if(C.size()==X[0]+X[1]+X[2]+X[3]) {
			cout<<"YES"<<endl;
			FORR(v,C) cout<<v<<" ";
			cout<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}