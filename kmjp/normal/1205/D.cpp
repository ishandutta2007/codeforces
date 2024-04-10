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
vector<int> E[1010];
int num[1010];
int U[1010],V[1010],W[1010];
int A[1010][1010];
int C[1010];

int from[3010];
int D[1010],step[2],nex[2];

pair<int,int> dfs_center(int cur,int pre) {
	pair<int,int> res=make_pair(1<<30,-1);
	int ma=0;
	num[cur]=1;
	
	FORR(r,E[cur]) if(r!=pre) {
		res=min(res,dfs_center(r,cur));
		ma=max(ma,num[r]);
		num[cur]+=num[r];
	}
	return min(res,make_pair(max(ma,N-num[cur]),cur));
}

int dfs(int cur,int pre) {
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[cur]+=dfs(e,cur);
	return C[cur];
}

void dfs2(int cur,int pre,int id) {
	if(pre!=-1) {
		nex[id]+=step[id];
		D[cur]=nex[id];
		W[A[pre][cur]]=D[cur]-D[pre];
	}
	FORR(e,E[cur]) if(e!=pre) dfs2(e,cur,id);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	MINUS(V);
	FOR(i,N-1) {
		cin>>U[i]>>V[i];
		E[U[i]].push_back(V[i]);
		E[V[i]].push_back(U[i]);
		A[U[i]][V[i]]=A[V[i]][U[i]]=i;
	}
	pair<int,int> p=dfs_center(1,-1);
	int c=p.second;
	dfs(c,-1);
	MINUS(from);
	from[0]=0;
	FORR(v,E[c]) {
		for(i=2000;i>=0;i--) if(from[i]!=-1 && from[i+C[v]]==-1) from[i+C[v]]=v;
	}
	
	vector<int> A;
	int a;
	FOR(i,2*N) if(i>=(N+1)/3 && (N-i-1)>=(N+1)/3 && from[i]>=0) {
		int cur=i;
		a=i;
		while(cur) {
			A.push_back(from[cur]);
			cur-=C[from[cur]];
		}
		break;
	}
	step[0]=1;
	step[1]=a+1;
	FORR(a,E[c]) dfs2(a,c,1^count(ALL(A),a));
	
	
	
	FOR(i,N-1) cout<<U[i]<<" "<<V[i]<<" "<<W[i]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}