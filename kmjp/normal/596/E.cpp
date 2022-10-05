#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int H,W,Q;
string S,T;
int DY[10],DX[10];

int nex[202*202];
int inloop[202*202];
int vis[202*202];
int mask[202*202];
vector<int> st;
vector<int> E[202*202];
int first[10];

int dfs(int cur,int first) {
	vis[cur]=first;
	if(vis[nex[cur]]==first) {
		st.push_back(nex[cur]);
		inloop[cur]=nex[cur];
		mask[inloop[cur]] |= 1<<S[cur];
		if(inloop[cur]==cur) return -1;
		return inloop[cur];
	}
	else if(vis[nex[cur]]>=0) {
		return -1;
	}
	else {
		inloop[cur]=dfs(nex[cur],first);
		mask[inloop[cur]] |= 1<<S[cur];
		if(inloop[cur]==-1 || inloop[cur]==cur) return -1;
		return inloop[cur];
	}
	
}

bool dfs2(int cur,int pos) {
	if(S[cur]==T[pos]) pos++;
	if(pos>=T.size()) return true;
	
	FORR(r,E[cur]) if(dfs2(r,pos)) return true;
	return false;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>H>>W>>Q;
	FOR(i,H) cin>>s, S+=s;
	FORR(r,S) r-='0';
	FOR(i,10) cin>>DY[i]>>DX[i];
	
	FOR(y,H) FOR(x,W) {
		int nx=x+DX[S[y*W+x]];
		int ny=y+DY[S[y*W+x]];
		
		if(nx<0 || nx>=W || ny<0 || ny>=H) nx=x, ny=y;
		nex[y*W+x]=ny*W+nx;
	}
	H*=W;
	MINUS(vis);
	MINUS(inloop);
	FOR(i,H) if(vis[i]==-1) dfs(i,i);
	
	
	FOR(i,H) if(inloop[i]==-1) {
		x=nex[i];
		if(inloop[x]>=0) x=inloop[x];
		E[x].push_back(i);
	}
	
	while(Q--) {
		cin>>T;
		reverse(ALL(T));
		FOR(i,10) first[i]=T.size();
		FOR(i,T.size()) {
			T[i]-='0';
			first[T[i]]=min(first[T[i]],i);
		}
		FORR(r,st) {
			int mi=T.size();
			FOR(i,10) if((mask[r] & (1<<i))==0) mi=min(mi,first[i]);
			if(mi==T.size() || dfs2(r,mi)) {
				cout<<"YES"<<endl;
				goto out;
			}
		}
		cout<<"NO"<<endl;
		out:
		;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}