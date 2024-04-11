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
char cmd[603030][7];
int ID[603030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	set<int> S;
	vector<int> V;
	int nex=1,ret=0;
	
	FOR(i,2*N) {
		scanf("%s",cmd[i]);
		if(cmd[i][0]=='a') {
			scanf("%d",&ID[x]);
			V.push_back(ID[x]);
		}
		else {
			if(V.size()) {
				if(V.back()==nex) {
					V.pop_back();
					nex++;
					continue;
				}
				ret++;
				FORR(r,V) S.insert(r);
				V.clear();
			}
			S.erase(nex);
			nex++;
		}
	}
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}