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

int H,W,Q;
bitset<1024> B[1024], rev;
int R[101010];
int A[101010],I[101010],J[101010];
vector<int> E[101010];

void dfs(int cur,int now) {
	int add=0,del=0,i;
	
	if(A[cur]==1 && B[I[cur]][J[cur]]==0) add++, B[I[cur]][J[cur]]=1, now++;
	if(A[cur]==2 && B[I[cur]][J[cur]]==1) del++, B[I[cur]][J[cur]]=0, now--;
	if(A[cur]==3) {
		now -= B[I[cur]].count();
		B[I[cur]] ^= rev;
		now += B[I[cur]].count();
	}
	
	R[cur]=now;
	FORR(r,E[cur]) dfs(r,now);
	if(A[cur+1]>=1 && A[cur+1]<=3) dfs(cur+1,now);
	
	if(A[cur]==3) {
		now -= B[I[cur]].count();
		B[I[cur]] ^= rev;
		now += B[I[cur]].count();
	}
	if(add) B[I[cur]][J[cur]]=0, now--;
	if(del) B[I[cur]][J[cur]]=1, now++;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(i,W) rev[i+1]=1;
	FOR(i,Q) {
		cin>>A[i+1]>>I[i+1];
		if(A[i+1]==4) E[I[i+1]].push_back(i+1);
		if(A[i+1]==1 || A[i+1]==2) cin>>J[i+1];
	}
	dfs(0,0);
	
	FOR(i,Q) cout<<R[i+1]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}