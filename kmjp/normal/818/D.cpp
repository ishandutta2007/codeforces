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

int N,A;
int C[101010];
map<int,int> M;
set<int> NG;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A;
	FOR(i,N) {
		cin>>C[i];
		if(C[i]!=A) M[C[i]]=0;
	}
	FOR(i,N) {
		if(C[i]==A) {
			vector<int> V;
			FORR(r,M) {
				r.second--;
				if(r.second<0) V.push_back(r.first);
			}
			FORR(v,V) M.erase(v), NG.insert(v);
		}
		else {
			if(NG.count(C[i])==0) M[C[i]]++;
		}
	}
	
	if(M.size()) cout<<M.begin()->first<<endl;
	else cout<<-1<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}