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
vector<vector<int>> E;

set<int> D[101010];

void dfs(int cur,int pre,int d) {
	D[d].insert(E[cur].size());
	FORR(e,E[cur]) if(e!=pre) dfs(e,cur,d+1);
}

int isok(int v) {
	int i;
	FOR(i,101010) D[i].clear();
	dfs(v,v,0);
	
	FOR(i,101010) if(D[i].size()>1) break;
	if(i==101010) {
		cout<<v+1<<endl;
		exit(0);
	}
	
}


pair<int,int> farthest(vector<vector<int>>& E, int cur,int pre,int d,vector<int>& D) {
	D[cur]=d;
	pair<int,int> r={d,cur};
	FORR(e,E[cur]) if(e!=pre) r=max(r, farthest(E,e,cur,d+1,D));
	return r;
}

pair<int,vector<int>> diameter(vector<vector<int>>& E) { // diameter,center
	vector<int> D[2];
	D[0].resize(E.size());
	D[1].resize(E.size());
	auto v1=farthest(E,0,0,0,D[0]);
	auto v2=farthest(E,v1.second,v1.second,0,D[0]);
	farthest(E,v2.second,v2.second,0,D[1]);
	pair<int,vector<int>> R;
	R.first = v2.first;
	//
	for(int i=E.size()-1;i>=0;i--) if(D[0][i]+D[1][i]==R.first && abs(D[0][i]-D[1][i])<=1) R.second.push_back(i);

	return R;
}

ll tree_normalize(vector<ll> T) {
	static ll momo[2]={1000000007,1000000009};
	static vector<ll> prim = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79};
	
	sort(ALL(T));
	int id=0,id2=1;
	ll a=1,b=1;
	FORR(r,T) {
		ll h=r>>32, l=r-(h<<32);
		(a+=h*prim[(id++)%prim.size()])%=momo[0];
		(b+=l*prim[(id2++)%prim.size()])%=momo[1];
	}
	return (a<<32)+b;
}

vector<ll> dfs2(int cur,int pre) {
	vector<ll> R={0,cur,0};
	vector<ll> V={1};
	FORR(e,E[cur]) if(e!=pre) {
		auto v=dfs2(e,cur);
		R[0]+=v[0];
		R[1]=v[1];
		V.push_back(v[2]);
	}
	if(V.size()==1) {
		R[0]=1;
		R[2]=1;
	}
	else {
		R[2]=tree_normalize(V);
	}
	return R;
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	E.resize(N);
	FOR(i,N-1) {
		cin>>x>>y;
		x--;
		y--;
		E[x].push_back(y);
		E[y].push_back(x);
	}
	
	auto C=diameter(E);
	FORR(c,C.second) {
		isok(c);
		
		vector<vector<ll>> cand;
		FORR(e,E[c]) cand.push_back(dfs2(e,c));
		map<ll,int> V;
		FORR(cc,cand) {
			V[cc[2]]++;
		}
		if(V.size()>=3) continue;
		FORR(cc,cand) if(V[cc[2]]==1 && cc[0]==1) isok(cc[1]);
	}
	
	cout<<-1<<endl;
		
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}