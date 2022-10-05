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
int X[1010],Y[1010];
vector<int> VX,VY;

vector<int> V[1010];
vector<int> H[1010];

vector<vector<int>> Vs,Hs;

template<int MV> class BIP {
	vector<int> tz;
	int vis[MV+1];
	int dfs(int v) {
		vis[v]=1;
		tz.push_back(v);
		FORR(r,E[v]) if(!vis[r] && (matchto[r]<0 || (!vis[matchto[r]] && dfs(matchto[r])))) {
			matchto[r]=v; matchto[v]=r;
			return 1;
		}
		return 0;
	}
public:
	int matchto[MV+1];
	vector<int> E[MV];
	void add_edge(int x,int y) { // add undirected edge
		E[x].push_back(y);E[y].push_back(x);
	}
	vector<pair<int,int> > match(int NV=MV){
		int i; MINUS(matchto);
		vector<pair<int,int> > R;
		ZERO(vis); tz.clear();
		vector<pair<int,int>> Vs;
		FOR(i,NV) if(E[i].size()) Vs.push_back({E[i].size(),i});
		sort(ALL(Vs));
		FORR(v,Vs) if(matchto[v.second]==-1) { FORR(t,tz) vis[t]=0; tz.clear(); dfs(v.second);}
		FORR(v,Vs) if(matchto[v.second]>i) R.push_back(make_pair(v.second,matchto[v.second]));
		return R;
	}
};
BIP<4020> bip;

int NG[3030];
map<vector<int>,int> M;
vector<vector<int>> ret[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		VX.push_back(X[i]);
		VY.push_back(Y[i]);
	}
	sort(ALL(VX));
	sort(ALL(VY));
	VX.erase(unique(ALL(VX)),VX.end());
	VY.erase(unique(ALL(VY)),VY.end());
	FOR(i,N) {
		X[i]=lower_bound(ALL(VX),X[i])-VX.begin();
		Y[i]=lower_bound(ALL(VY),Y[i])-VY.begin();
		V[X[i]].push_back(Y[i]);
		H[Y[i]].push_back(X[i]);
	}
	
	FOR(i,N) {
		if(V[i].size()>1) {
			sort(ALL(V[i]));
			FOR(j,V[i].size()-1) {
				Vs.push_back({i,V[i][j],i,V[i][j+1]});
				M[{i,V[i][j],i,V[i][j+1]}]=Vs.size()-1;
			}
		}
	}
	FOR(i,N) {
		if(H[i].size()>1) {
			sort(ALL(H[i]));
			FOR(j,H[i].size()-1) {
				Hs.push_back({H[i][j],i,H[i][j+1],i});
				M[{H[i][j],i,H[i][j+1],i}]=Vs.size()+Hs.size()-1;
			}
		}
	}
	
	FOR(x,Vs.size()) FOR(y,Hs.size()) {
		vector<int> v=Vs[x];
		vector<int> h=Hs[y];
		if(h[0]<v[0] && v[0]<h[2] && v[1]<h[1] && h[1]<v[3]) bip.add_edge(x,Vs.size()+y);
	}
	
	bip.match(Vs.size()+Hs.size());
	
	
	queue<int> Q;
	int vis[6060]={};
	FOR(i,Vs.size()) if(bip.matchto[i]==-1 && bip.E[i].size()) {
		vis[i]=1;
		Q.push(i);
	}
	
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,bip.E[x]) if(vis[e]==0) {
			vis[e]=1;
			if(bip.matchto[e]!=-1 && vis[bip.matchto[e]]==0) {
				vis[bip.matchto[e]]=1;
				Q.push(bip.matchto[e]);
			}
		}
	}
	FOR(i,Vs.size()) if(vis[i]==0 && bip.E[i].size()>0) NG[i]=1;
	FOR(i,Hs.size()) NG[i+Vs.size()]=vis[i+Vs.size()];
	
	
	
	FOR(i,N) {
		if(V[i].size()) {
			pair<int,int> L={i,V[i][0]},R={i,V[i][0]};
			for(j=1;j<V[i].size();j++) {
				x=M[{i,V[i][j-1],i,V[i][j]}];
				if(NG[x]) {
					ret[0].push_back({L.first,L.second,R.first,R.second});
					L={i,V[i][j]};
				}
				R={i,V[i][j]};
			}
			ret[0].push_back({L.first,L.second,R.first,R.second});
		}
		if(H[i].size()) {
			pair<int,int> L={H[i][0],i},R={H[i][0],i};
			for(j=1;j<H[i].size();j++) {
				x=M[{H[i][j-1],i,H[i][j],i}];
				if(NG[x]) {
					ret[1].push_back({L.first,L.second,R.first,R.second});
					L={H[i][j],i};
				}
				R={H[i][j],i};
			}
			ret[1].push_back({L.first,L.second,R.first,R.second});
		}
	}
	
	for(i=1;i>=0;i--) {
		cout<<ret[i].size()<<endl;
		FORR(r,ret[i]) cout<<VX[r[0]]<<" "<<VY[r[1]]<<" "<<VX[r[2]]<<" "<<VY[r[3]]<<endl;
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}