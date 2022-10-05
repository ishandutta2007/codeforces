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
ll X1[101010],X2[101010],Y1[101010],Y2[101010];
ll L,R,T,B;

int dfs(vector<int>& A) {
	if(A.size()<=1) return 1;
	
	int i,R;
	vector<pair<int,int>> C;
	//X
	FORR(a,A) C.push_back({X1[a],X2[a]});
	sort(ALL(C));
	R=C[0].second;
	
	for(i=1;i<C.size();i++) {
		if(C[i].first>=R) {
			vector<int> S,T;
			
			FORR(a,A) {
				if(X2[a]<=C[i].first) S.push_back(a);
				else T.push_back(a);
			}
			return dfs(S)&dfs(T);
		}
		else {
			R=max(R,C[i].second);
		}
	}
	C.clear();
	// Y
	FORR(a,A) C.push_back({Y1[a],Y2[a]});
	sort(ALL(C));
	R=C[0].second;
	for(i=1;i<C.size();i++) {
		if(C[i].first>=R) {
			vector<int> S,T;
			
			FORR(a,A) {
				if(Y2[a]<=C[i].first) S.push_back(a);
				else T.push_back(a);
			}
			return dfs(S)&dfs(T);
		}
		else {
			R=max(R,C[i].second);
		}
	}
	
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X1[i]>>Y1[i]>>X2[i]>>Y2[i];
	}
	vector<int> V;
	FOR(i,N) V.push_back(i);
	
	if(dfs(V)) _P("YES\n");
	else _P("NO\n");
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}