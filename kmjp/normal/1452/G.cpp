#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------

int N,K;
vector<int> E[202020];
int D[202020];
int hi[202020];
int ret[202020];
vector<int> cand[202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) D[i]=303030;
	FOR(i,N-1) {
		cin>>x>>y;
		E[x-1].push_back(y-1);
		E[y-1].push_back(x-1);
	}
	queue<int> Q;
	cin>>K;
	FOR(i,K) {
		cin>>x;
		D[x-1]=0;
		Q.push(x-1);
	}
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		cand[D[x]].push_back(x);
		FORR(e,E[x]) if(D[e]>D[x]+1) {
			D[e]=D[x]+1;
			Q.push(e);
		}
	}
	
	for(i=N;i>=0;i--) if(cand[i].size()) {
		queue<pair<int,int>> Q;
		FORR(c,cand[i]) if(hi[c]<D[c]) {
			ret[c]=max(ret[c],i);
			hi[c]=D[c];
			Q.push({D[c],c});
		}
		while(Q.size()) {
			int h=Q.front().first;
			int cur=Q.front().second;
			Q.pop();
			h--;
			if(h==0) continue;
			FORR(e,E[cur]) if(hi[e]<min(D[e],h)) {
				hi[e]=min(D[e],h);
				ret[e]=max(ret[e],i);
				Q.push({hi[e],e});
			}
		}
	}
	FOR(i,N) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}