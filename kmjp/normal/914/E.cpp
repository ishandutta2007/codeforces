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
vector<int> E[202020];
string S;
int mask[1<<20];
int M[202020];
ll ret[202020];

int vis[201010];
int NV[201010];

int dfs(int cur,int pre) {
	NV[cur]=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) NV[cur]+=dfs(e,cur);
	return NV[cur];
}

int dfs2(int cur,int pre,int TNV) {
	int tot=1;
	int ok=1;
	FORR(e,E[cur]) if(e!=pre && vis[e]==0) {
		int c = dfs2(e,cur,TNV);
		if(c!=-1) return c;
		tot += NV[e];
		if(NV[e]*2>TNV) ok=0;
	}
	if((TNV-tot)*2>TNV) ok=0;
	if(ok) return cur;
	return -1;
}

vector<int> rec;

ll dfs3(int cur,int pre,int m) {
	m ^= M[cur];
	rec.push_back(m);
	
	int i;
	ll add=0;
	add+=mask[m];
	FOR(i,20) add+=mask[m^(1<<i)];
	FORR(e,E[cur]) if(vis[e]==0 && e!=pre) add+=dfs3(e,cur,m);
	ret[cur]+=add;
	return add;
}

void hoge(int C) {
	vector<int> hist;
	hist.push_back(M[C]);
	mask[M[C]]++;
	
	ret[C]++;
	
	FORR(e,E[C]) if(vis[e]==0) {
		rec.clear();
		ret[C]+=dfs3(e,C,0);
		FORR(r,rec) {
			hist.push_back(M[C]^r);
			mask[M[C]^r]++;
		}
	}
	
	FORR(e,hist) mask[e]--;
	hist.clear();
	
	reverse(ALL(E[C]));
	FORR(e,E[C]) if(vis[e]==0) {
		rec.clear();
		dfs3(e,C,0);
		FORR(r,rec) {
			hist.push_back(M[C]^r);
			mask[M[C]^r]++;
		}
	}
	FORR(e,hist) mask[e]--;
	hist.clear();
}


void split(int cur) {
	int TNV = dfs(cur,-1);
	if(TNV==0) return;
	int center=dfs2(cur,-1,TNV);
	hoge(center);
	vis[center]=1;
	FORR(e,E[center]) if(vis[e]==0) split(e);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	cin>>S;
	FOR(i,N) {
		S[i]-='a';
		M[i]=1<<S[i];
	}
	
	split(0);
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}