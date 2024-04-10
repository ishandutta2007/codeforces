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
vector<int> E[401010];
set<int> SE[401010];
int FD[402020],D[402020],CD[402020];
vector<pair<int,int>> MD[402020];
int nodel[404040];

int DD,D2;
vector<int> C;

void dfs(int cur,int pre) {
	if(pre!=-1) D[cur]=D[pre]+1;
	int i;
	FOR(i,E[cur].size()) {
		if(E[cur][i]==pre) {
			E[cur].erase(E[cur].begin()+i);
			break;
		}
	}
	
	
	CD[cur]=-1;
	if(E[cur].size()==0) {
		MD[cur].push_back({D[cur],cur});
	}
	else if(E[cur].size()==1) {
		FORR(e,E[cur]) {
			dfs(e,cur);
			CD[cur]=CD[e];
			MD[cur]=MD[e];
		}
	}
	else {
		vector<vector<int>> cand;
		FORR(e,E[cur]) {
			dfs(e,cur);
			if(CD[e]>=0) cand.push_back({D[CD[e]],MD[e][0].first+MD[e][1].first-2*D[CD[e]],e});
		}
		
		sort(ALL(cand));
		reverse(ALL(cand));
		if(cand.size()>=2) {
			int len=cand[0][0]+cand[1][0]-2*D[cur];
			int slen=cand[0][1]+cand[1][1];
			
			if(len>DD || (len==DD && slen>D2)) {
				DD=len;
				D2=slen;
				C.clear();
				C.push_back(MD[cand[0][2]][0].second+1);
				C.push_back(MD[cand[1][2]][0].second+1);
				C.push_back(MD[cand[0][2]][1].second+1);
				C.push_back(MD[cand[1][2]][1].second+1);
			}
			
		}
		if(cand.size()>=1) {
			CD[cur]=CD[cand[0][2]];
			MD[cur]=MD[cand[0][2]];
		}
		else {
			CD[cur]=cur;
			FORR(e,E[cur]) MD[cur].push_back(MD[e][0]);
			sort(ALL(MD[cur]));
			reverse(ALL(MD[cur]));
			MD[cur].resize(2);
		}
	}
}

pair<int,int> farthest(int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,SE[cur]) if(e!=pre) r=max(r, farthest(e,cur,d+1,D));
	return r;
}

//
int diameter(int S) { // diameter,center
	vector<int> D[2];
	D[0].resize(N);
	D[1].resize(N);
	auto v1=farthest(S,0,0,D[0]);
	auto v2=farthest(v1.second,v1.second,0,D[0]);
	farthest(v2.second,v2.second,0,D[1]);
	
	vector<pair<int,int>> R;
	//
	int i;
	FOR(i,N) if(SE[i].size() && D[0][i]+D[1][i]==v2.first) R.push_back({D[0][i],i});
	sort(ALL(R));
	return R[R.size()/2].second;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int nex=N;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(nex);
		E[nex].push_back(x-1);
		E[y-1].push_back(nex);
		E[nex].push_back(y-1);
		SE[x-1].insert(nex);
		SE[nex].insert(x-1);
		SE[y-1].insert(nex);
		SE[nex].insert(y-1);
		nex++;
	}
	N=nex;
	queue<int> Q;
	int R;
	FOR(i,N) {
		if(E[i].size()>=3) nodel[i]=1, R=i;
		if(E[i].size()==1) Q.push(i);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,SE[x]) {
			SE[e].erase(x);
			if(nodel[e]==0 && SE[e].size()==1) Q.push(e);
		}
		SE[x].clear();
	}
	R=diameter(R);
	
	dfs(R,-1);
	cout<<C[0]<<" "<<C[1]<<endl;
	cout<<C[2]<<" "<<C[3]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}