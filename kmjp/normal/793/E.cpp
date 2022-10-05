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

int N,A,B,C,D;
int P[5050];
int PD[4];
bitset<5050> BS[4],LE;

int num[5050];
vector<int> E[5050];
vector<int> L;

int dfs(int cur) {
	if(E[cur].empty()) {
		num[cur]=1;
	}
	else {
		FORR(e,E[cur]) num[cur]+=dfs(e);
	}
	return num[cur];
}

int hoge(bitset<5050> A,bitset<5050> B,int NA,int S,vector<int> cand) {
	int T=num[0];
	if(T%2) return 0;
	B<<=NA+S;
	FORR(r,cand) B|=B<<r;
	int i;
	FOR(i,5050) if(i+T/2<5050 && A[i] && B[i+T/2]) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>A>>B>>C>>D;
	A--,B--,C--,D--;
	FOR(i,N-1) {
		cin>>x;
		P[i+1]=x-1;
		E[x-1].push_back(i+1);
	}
	dfs(0);
	
	PD[0]=A;
	PD[1]=B;
	PD[2]=C;
	PD[3]=D;
	FOR(i,4) {
		BS[i][0]=1;
		while(P[PD[i]]!=0) {
			x = P[PD[i]];
			FORR(e,E[x]) if(x!=PD[i]) {
				y = num[e];
				BS[i] |= BS[i]<<y;
			}
			PD[i]=P[PD[i]];
		}
	}
	
	vector<int> cand;
	FORR(e,E[0]) {
		FOR(i,4) if(e==PD[i]) break;
		if(i==4) cand.push_back(num[e]);
	}
	
	if(hoge(BS[0],BS[1],num[PD[0]],num[PD[2]],cand) && hoge(BS[2],BS[3],num[PD[2]],num[PD[1]],cand)) return _P("YES\n");
	if(hoge(BS[0],BS[1],num[PD[0]],num[PD[3]],cand) && hoge(BS[2],BS[3],num[PD[2]],num[PD[1]],cand)) return _P("YES\n");
	_P("NO\n");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}