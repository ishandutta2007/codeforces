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

int N,K;
ll L[303030],R[303030];

map<int,vector<int>> E;

int ma=0;
int id=-1;


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		E[L[i]].push_back(i);
		E[R[i]].push_back(i+1000000);
	}
	set<pair<int,int>> S;
	FORR(r,E) {
		sort(ALL(r.second));
		
		FORR(e,r.second) {
			if(e<1000000) {
				S.insert({R[e],e});
				if(S.size()>K) S.erase(S.begin());
				if(S.size()==K) {
					ll d=S.begin()->first-r.first+1;
					if(d>ma) {
						ma=d;
						id=e;
					}
				}
			}
			else {
				S.erase({R[e-1000000],e-1000000});
			}
		}
	}
	
	if(id==-1) {
		_P("0\n");
		FOR(i,K) _P("%d%c",i+1,(i==K-1)?'\n':' ');
	}
	S.clear();
	FORR(r,E) {
		sort(ALL(r.second));
		
		FORR(e,r.second) {
			if(e<1000000) {
				S.insert({R[e],e});
				if(S.size()>K) S.erase(S.begin());
				if(e==id) {
					_P("%d\n",ma);
					FORR(r,S) _P("%d ",r.second+1);
					_P("\n");
					return;
				}
			}
			else {
				S.erase({R[e-1000000],e-1000000});
			}
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