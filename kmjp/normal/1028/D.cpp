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
string S[404040];
int P[404040];
ll mo=1000000007;
map<int,int> m;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>S[i]>>P[i];
		m[P[i]]=3;
	}
	
	set<int> C[2],L;
	ll ret=1;
	FOR(i,N) {
		if(S[i]=="ADD") {
			L.insert(P[i]);
			C[0].insert(P[i]);
			C[1].insert(P[i]);
		}
		else {
			while(C[0].size() && *C[0].begin()<P[i]) {
				x=*C[0].begin();
				m[x]&=1;
				C[0].erase(x);
			}
			while(C[1].size() && *C[1].rbegin()>P[i]) {
				x=*C[1].rbegin();
				m[x]&=2;
				C[1].erase(x);
			}
			if(m[P[i]]==0) ret=0;
			else if(m[P[i]]==3) ret=ret*2%mo;
			
			C[0].erase(P[i]);
			C[1].erase(P[i]);
			L.erase(P[i]);
			m.erase(P[i]);
		}
	}
	
	vector<int> V;
	FORR(a,m) V.push_back(a.second);
	for(i=1;i<V.size();i++) if((V[i-1]&1)==0) V[i]&=2;
	for(i=(int)V.size()-2;i>=0;i--) if((V[i+1]&2)==0) V[i]&=1;
	int num=0;
	FORR(v,V) {
		if(v==0) ret=0;
		if(v==3) num++;
	}
	
	ret=ret*(num+1)%mo;
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}