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

int X[3],Y[3];
int X2[3],Y2[3];
pair<int,char> P[3];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	FOR(i,3) cin>>X2[i]>>Y2[i], P[i]={i,'A'+i};
	
	do {
		for(int mask=0;mask<8;mask++) {
			FOR(i,3) {
				if(mask&(1<<i)) X[i]=X2[P[i].first],Y[i]=Y2[P[i].first];
				else X[i]=Y2[P[i].first],Y[i]=X2[P[i].first];
			}
			
			// straight
			if(X[0]==X[1] && X[1]==X[2] && X[0]==Y[0]+Y[1]+Y[2]) {
				_P("%d\n",Y[0]+Y[1]+Y[2]);
				FOR(i,3) {
					FOR(y,Y[i]) {
						FOR(x,X[i]) _P("%c",P[i].second);
						_P("\n");
					}
				}
				return;
			}
			
			if(X[0]+X[1]==X[2] && Y[0]==Y[1] && X[2]==Y[0]+Y[2]) {
				_P("%d\n",Y[0]+Y[2]);
				FOR(y,Y[2]) {
					FOR(x,X[2]) _P("%c",P[2].second);
					_P("\n");
				}
				FOR(y,Y[0]) {
					FOR(x,X[0]) _P("%c",P[0].second);
					FOR(x,X[1]) _P("%c",P[1].second);
					_P("\n");
				}
				return;
			}
		}
	} while(next_permutation(P,P+3));
	_P("-1\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}