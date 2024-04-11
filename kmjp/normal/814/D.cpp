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
ll X[1010],Y[1010],R[1010];
double S[1010];
double memo[1010][4];
int P[1010];
vector<int> E[1010];

double dfs(int cur,int mask) {
	if(memo[cur][mask]==0) {
		if(mask==0) {
			memo[cur][mask]=S[cur];
			FORR(e,E[cur]) memo[cur][mask] += dfs(e,1);
		}
		else if(mask==3) {
			memo[cur][mask]=-S[cur];
			FORR(e,E[cur]) memo[cur][mask] += dfs(e,1);
		}
		else {
			double a=S[cur],b=-S[cur];
			FORR(e,E[cur]) a += dfs(e,3);
			FORR(e,E[cur]) b += dfs(e,0);
			memo[cur][mask] = max(a,b);
		}
	}
	return memo[cur][mask];
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i]>>R[i];
		S[i]=pi*R[i]*R[i];
	}
	FOR(i,N) {
		P[i]=-1;
		FOR(j,N) if(R[j]>R[i] && (X[j]-X[i])*(X[j]-X[i])+(Y[j]-Y[i])*(Y[j]-Y[i])<=R[j]*R[j]) {
			if(P[i]==-1 || R[j]<R[P[i]]) P[i]=j;
		}
		if(P[i]!=-1) E[P[i]].push_back(i);
	}
	double ret=0;
	FOR(i,N) if(P[i]==-1) ret+=dfs(i,0);
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}