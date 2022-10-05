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

int N,M;
pair<int,int> S[202020];

int C,U;
int A[202020],B[202020];
map<int,vector<int>> MP;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) {
		cin>>x;
		MP[x].push_back(i);
	}
	
	FOR(i,M) {
		cin>>x;
		S[i]={x,i};
	}
	sort(S,S+M);
	FOR(i,M) {
		x = S[i].first;
		j =0;
		while(x) {
			if(MP.count(x)) {
				y = MP[x].back();
				A[S[i].second]=j;
				B[y]=S[i].second+1;
				MP[x].pop_back();
				if(MP[x].empty()) MP.erase(x);
				C++;
				U+=j;
				break;
			}
			if(x==1) break;
			j++;
			x=x/2+x%2;
		}
	}
	
	
	
	
	_P("%d %d\n",C,U);
	FOR(i,M) _P("%d%c",A[i],(i==M-1)?'\n':' ');
	FOR(i,N) _P("%d%c",B[i],(i==N-1)?'\n':' ');
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}