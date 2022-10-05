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

ll L,R;
string LS,RS;
int D[10];
int ret,pat;
string A0,A9;

int hoge(int d,string& L,string& R) {
	if(d==L.size()) return 1;
	int ret=0;
	
	
	if(L[d]==R[d]) {
		if(D[L[d]]) {
			D[L[d]]--;
			ret=hoge(d+1,L,R);
			D[L[d]]++;
		}
		return ret;
	}
	int x;
	for(x=L[d]+1;x<R[d];x++) {
		if(D[x]) return 1;
	}
	if(D[L[d]]) {
		D[L[d]]--;
		ret |= hoge(d+1,L,A9);
		D[L[d]]++;
		if(ret) return 1;
	}
	if(D[R[d]]) {
		D[R[d]]--;
		ret |= hoge(d+1,A0,R);
		D[R[d]]++;
	}
	return ret;
}


int hoge() {
	pat++;
	D[0]++;
	if(D[0]!=19) ret+=hoge(0,LS,RS);
	D[0]--;
}

void dfs(int cur,int left) {
	if(cur==10) {
		if(left==0) hoge();
		return;
	}
	int i;
	FOR(i,left+1) {
		D[cur]=i;
		dfs(cur+1,left-i);
	}
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>LS>>RS;
	while(LS.size()<19) LS="0"+LS;
	while(RS.size()<19) RS="0"+RS;
	FORR(c,LS) c-='0';
	FORR(c,RS) c-='0';
	A0=string(19,0);
	A9=string(19,9);
	
	dfs(0,18);
	cout<<ret<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}