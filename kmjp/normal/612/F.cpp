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

int N,S;
int A[2020];
vector<int> V;
vector<int> pos[2020];

int dist[2020][2020];
int from[2020][2020];
int rev[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	S--;
	FOR(i,N) cin>>A[i], V.push_back(A[i]);
	V.push_back(-1<<30);
	sort(ALL(V));
	V.erase(unique(ALL(V)),V.end());
	FOR(i,N) {
		A[i]=lower_bound(ALL(V),A[i])-V.begin();
		pos[A[i]].push_back(i);
		pos[A[i]].push_back(N+i);
		pos[A[i]].push_back(2*N+i);
		pos[A[i]].push_back(3*N+i);
		pos[A[i]].push_back(4*N+i);
	}
	
	pos[0].push_back(S);
	pos[0].push_back(1*N+S);
	pos[0].push_back(2*N+S);
	pos[0].push_back(3*N+S);
	pos[0].push_back(4*N+S);
	FOR(i,N+1) {
		sort(ALL(pos[i]));
		if(i) FOR(j,pos[i].size()) rev[pos[i][j]]=j;
	}
	FOR(i,N+1) FOR(j,N+1) dist[i][j]=1<<30;
	dist[0][S]=0;
	
	FOR(i,V.size()-1) {
		FOR(x,pos[i].size()/5) {
			if(pos[i+1].size()==5) {
				int st=pos[i][x];
				int ed=pos[i+1][0];
				int tot=dist[i][st]+min(abs(st-ed),N-abs(st-ed));
				if(tot<dist[i+1][ed]) {
					dist[i+1][ed]=tot;
					from[i+1][ed]=st;
				}
			}
			else {
				FOR(y,pos[i+1].size()/5) {
					int st=pos[i][x+2*pos[i].size()/5];
					int ed=pos[i+1][y+2*pos[i+1].size()/5];
					int pre=pos[i+1][y+2*pos[i+1].size()/5-1];
					int nex=pos[i+1][y+2*pos[i+1].size()/5+1];
					
					if(ed<st) ed+=N, pre+=N, nex+=N;
					
					// counter clock
					int tot=N-(ed-st);
					if(pre>st) tot+=(pre-st)*2;
					//_P("%d (%d->(%d,%d,%d)) %d %d %d\n",i,st,pre,ed,nex,pos[i][x],pos[i+1][y],tot);
					// clock
					if(nex>=st+N) {
						tot=min(tot,ed-st);
					}
					else {
						tot=min(tot,2*(N-(nex-st))+(ed-st));
					}
					
					//_P("%d (%d->(%d,%d,%d)) %d %d %d\n",i,st,pre,ed,nex,pos[i][x],pos[i+1][y],tot);
					ed=pos[i+1][y];
					tot+=dist[i][pos[i][x]];
					if(tot<dist[i+1][ed]) {
						dist[i+1][ed]=tot;
						from[i+1][ed]=pos[i][x];
					}
				}
			}
		}
	}
	
	int st=min_element(dist[V.size()-1],dist[V.size()-1]+N)-dist[V.size()-1];
	_P("%d\n",dist[V.size()-1][st]);
	
	vector<int> R;
	for(i=V.size()-1;i>=1;i--) {
		R.push_back(st);
		st=from[i][st];
	}
	R.push_back(S);
	reverse(ALL(R));
	FOR(i,R.size()-1) {
		int st=2*N+R[i];
		int y=rev[R[i+1]];
		int ed=pos[i+1][y+2*pos[i+1].size()/5];
		int pre=pos[i+1][y+2*pos[i+1].size()/5-1];
		int nex=pos[i+1][y+2*pos[i+1].size()/5+1];
		if(st>ed) st-=N;
		
		int tot1=N-(ed-st);
		if(pre>st) tot1+=(pre-st)*2;
		
		int tot2=ed-st;
		if(nex<st+N) tot2+=2*(N-(nex-st));
		vector<int> pat;
		pat.push_back(st);
		
		if(tot1<tot2) {
			FORR(r,pos[i+1]) if(r>=st && r<=pre) pat.push_back(r);
			reverse(ALL(pos[i+1]));
			FORR(r,pos[i+1]) if(r>=ed && r<st+N) pat.push_back(r-N);
			reverse(ALL(pos[i+1]));
		}
		else {
			reverse(ALL(pos[i+1]));
			FORR(r,pos[i+1]) if(r<st+N && r>=nex) pat.push_back(r-N);
			reverse(ALL(pos[i+1]));
			FORR(r,pos[i+1]) if(r>=st && r<=ed) pat.push_back(r);
		}
		//_P("%d->%d\n",R[i],R[i+1]);
		//FORR(r,pat) _P("[%d]",r);
		FOR(j,pat.size()-1) {
			x=pat[j+1]-pat[j];
			if(x>=0) _P("+%d\n",x);
			else _P("%d\n",x);
		}
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}