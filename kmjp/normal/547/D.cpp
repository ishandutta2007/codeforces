#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[202000],Y[202000];
map<pair<int,int>,int> M;
string S;

set<int> XE[202000],YE[202000];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		M[{X[i],Y[i]}]=i;
		XE[X[i]].insert(Y[i]);
		YE[Y[i]].insert(X[i]);
		S+=" ";
	}
	
	stack<pair<int,int> > Q;
	FOR(j,2) {
		FOR(i,202000) {
			if(j==0) {
				if(XE[i].size()%2) Q.push({i,1});
				if(YE[i].size()%2) Q.push({-i,1});
			}
			else {
				if(XE[i].size()%2==0 && XE[i].size()) Q.push({i,1});
				if(YE[i].size()%2==0 && YE[i].size()) Q.push({-i,1});
			}
		}
		
		while(Q.size()) {
			int cur=Q.top().first;
			if(Q.top().second) x=0;
			x^=1;
			Q.pop();
			
			if(cur>0) {
				if(XE[cur].size()==0) continue;
				if(j==0 && XE[cur].size()%2==0) continue;
				
				int tar=*XE[cur].begin();
				XE[cur].erase(tar);
				if(x) S[M[{cur,tar}]]='r';
				else S[M[{cur,tar}]]='b';
				YE[tar].erase(cur);
				Q.push({-tar,0});
			}
			else {
				cur=-cur;
				if(YE[cur].size()==0) continue;
				if(j==0 && YE[cur].size()%2==0) continue;
				
				int tar=*YE[cur].begin();
				YE[cur].erase(tar);
				if(x) S[M[{tar,cur}]]='r';
				else S[M[{tar,cur}]]='b';
				XE[tar].erase(cur);
				Q.push({tar,0});
			}
		}
	}
	
	cout<<S<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}