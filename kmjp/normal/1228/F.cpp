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

int D,N;
vector<int> E[1<<17];
int C[1<<17],P[1<<17];
set<int> R;

int dfs(int cur,int pre) {
	P[cur]=pre;
	C[cur]=1;
	FORR(e,E[cur]) if(e!=pre) C[cur]+=dfs(e,cur);
	return C[cur];
}

int ok(int cur,int pre) {
	vector<int> C;
	FORR(e,E[cur]) if(e!=pre) {
		C.push_back(ok(e,cur));
	}
	sort(ALL(C));
	if(C.empty()) return 0;
	if(C[0]==-1) return -1;
	if(C.size()==1) {
		if(C[0]==0) {
			R.insert(cur+1);
			return C[0]+1;
		}
	}
	if(C.size()==2) {
		if(C[0]==C[1]) {
			return C[0]+1;
		}
	}
	if(C.size()==3) {
		if(C[0]==C[1]&&C[0]+1==C[2]) {
			R.insert(cur+1);
			return C[2]+1;
		}
	}
	return -1;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>D;
	N=(1<<D)-2;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	
	dfs(0,-1);
	vector<int> CV;
	int cur;
	FOR(cur,N) {
		if(E[cur].size()==1) {
			vector<int> cand;
			FORR(e,E[cur]) {
				if(e==P[cur]) {
					cand.push_back(N-C[cur]);
				}
				else {
					cand.push_back(C[e]);
				}
			}
			sort(ALL(cand));
			if(cand[0]==1) CV.push_back(cur);
		}
		if(E[cur].size()==2) {
			vector<int> cand;
			FORR(e,E[cur]) {
				if(e==P[cur]) {
					cand.push_back(N-C[cur]);
				}
				else {
					cand.push_back(C[e]);
				}
			}
			sort(ALL(cand));
			if(cand[0]+1==cand[1]) CV.push_back(cur);
		}
		if(E[cur].size()==3) {
			vector<int> cand;
			FORR(e,E[cur]) {
				if(e==P[cur]) cand.push_back(N-C[cur]);
				else cand.push_back(C[e]);
			}
			sort(ALL(cand));
			if(cand[0]==cand[1] && cand[0]+cand[1]+1==cand[2]) CV.push_back(cur);
		}
	}
	set<int> TR;
	FORR(c,CV) {
		if(ok(c,-1)>=0) {
			FORR(r,R) TR.insert(r);
		}
	}
	
	cout<<TR.size()<<endl;
	FORR(r,TR) cout<<r<<" ";
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}