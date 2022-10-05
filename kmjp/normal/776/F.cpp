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

vector<vector<int>> ST;
vector<vector<int>> R;

int N;
int M;
int S[101010],E[101010];
int A[101010],B[101010];
map<pair<int,int>,int> P;
int T[101010];
vector<int> EV[101010];
int ret[101010];

int vis[101010];
int NV[101010];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,EV[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

void split(int cur,int id) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	dfs(cur,-1);
	int center=dfs2(cur,-1,TNV);
	ret[center]=id;
	vis[center]=1;
	FORR(e,EV[center]) if(vis[e]==0) split(e,id+1);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		if(A[i]>B[i]) swap(A[i],B[i]);
		S[A[i]]++;
		E[B[i]]++;
		P[{A[i],B[i]}]=i;
		
	}
	ST.push_back(vector<int>());
	FOR(i,N) {
		ST.back().push_back(i);
		FOR(j,E[i]) {
			R.push_back(ST.back());
			ST.pop_back();
			ST.back().push_back(i);
		}
		FOR(j,S[i]) {
			ST.push_back(vector<int>());
			ST.back().push_back(i);
		}
	}
	while(ST.size()) {
		R.push_back(ST.back());
		ST.pop_back();
	}
	FORR(r,R) {
		sort(ALL(r));
		reverse(ALL(r));
	}
	
	sort(ALL(R));
	MINUS(T);
	FOR(i,R.size()) {
		reverse(ALL(R[i]));
		FOR(j,R[i].size()-1) {
			if(R[i][j]+1!=R[i][j+1]) {
				x = P[{R[i][j],R[i][j+1]}];
				if(T[x]==-1) T[x]=i;
				else {
					EV[T[x]].push_back(i);
					EV[i].push_back(T[x]);
				}
			}
		}
		if(!(R[i][0]==0 && R[i].back()==N-1)) {
			x = P[{R[i][0],R[i].back()}];
			if(T[x]==-1) T[x]=i;
			else {
				EV[T[x]].push_back(i);
				EV[i].push_back(T[x]);
			}
		}
	}
	
	split(0,1);
	FOR(i,R.size()) _P("%d ",ret[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}