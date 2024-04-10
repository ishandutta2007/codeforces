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
string S;
ll K;
vector<pair<int,int>> V;
int mat[1010][1010];

ll pat[1010][1010];

void dfs(vector<int> A,int len) {
	if(A.empty()) return;
	if(len) V.push_back({A[0],len});
	
	vector<int> C[26];
	FORR(v,A) {
		if(v+len>=N) continue;
		C[S[v+len]-'a'].push_back(v);
	}
	int i;
	FOR(i,26) dfs(C[i],len+1);
	
}

ll num(int id) {
	if(id<0) return 1LL<<60;
	int A=V[id].first;
	int B=V[id].second;
	
	ZERO(pat);
	int i,x,y;
	pat[0][0]=1;
	FOR(i,M) {
		FOR(x,N) if(pat[i][x]) {
			if(mat[x][A]>=B) {
				pat[i+1][x+B]=min(pat[i+1][x+B]+pat[i][x],1LL<<60);
			}
			else {
				if(x+mat[x][A]<N&&(A+mat[x][A]>=N || S[x+mat[x][A]]>S[A+mat[x][A]])) {
					pat[i+1][x+mat[x][A]+1]=min(pat[i+1][x+mat[x][A]+1]+pat[i][x],1LL<<60);
				}
			}
		}
		
		for(x=1;x<=N;x++) {
			pat[i+1][x]=min(pat[i+1][x]+pat[i+1][x-1],1LL<<60);
		}
	}
	return pat[M][N];
	
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	cin>>S;
	
	for(int len=1;len<=N-1;len++) {
		for(x=N-1;x-len>=0;x--) {
			if(S[x]==S[x-len]) mat[x-len][x]=mat[x][x-len]=mat[x-len+1][x+1]+1;
		}
	}
	FOR(i,N) mat[i][i]=N-i;
	
	vector<int> A;
	FOR(i,N) A.push_back(i);
	dfs(A,0);
	
	int ret=V.size();
	for(i=21;i>=0;i--) if(num(ret-(1<<i))<K) ret-=1<<i;
	ret--;
	cout<<S.substr(V[ret].first,V[ret].second)<<endl;
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}