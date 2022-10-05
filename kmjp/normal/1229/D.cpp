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
 
int N,K;
int P[202020];

vector<vector<int>> V;
map<vector<int>,int> T;
int pre[120];
int did[120];
int mult[120][120];

 
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	
	vector<int> W;
	FOR(i,K) W.push_back(i);
	set<pair<int,int>> S;
	do {
		V.push_back(W);
		x=T.size();
		T[W]=x;
		pre[x]=N;
		S.insert({N,x});
	} while(next_permutation(ALL(W)));
	
	
	FOR(x,V.size()) FOR(y,V.size()) {
		vector<int> a=V[x];
		vector<int> b=V[y];
		vector<int> c;
		FORR(i,b) c.push_back(a[i]);
		mult[x][y]=T[c];
	}
	
	
	FOR(y,N) {
		vector<int> C(K);
		FOR(x,K) cin>>C[x], C[x]--;
		P[y]=T[C];
	}
	
	ll ret=0;
	for(x=N-1;x>=0;x--) {
		ZERO(did);
		vector<int> C;
		S.erase({pre[P[x]],P[x]});
		pre[P[x]]=x;
		S.insert({pre[P[x]],P[x]});
		
		int num=1;
		did[0]=1;
		int pre=x;
		FORR(s,S) {
			ret+=(s.first-pre)*num;
			pre=s.first;
			if(did[s.second]==0) {
				C.push_back(s.second);
				num=1;
				ZERO(did);
				did[0]=1;
				queue<int> Q;
				Q.push(0);
				while(Q.size()) {
					int cur=Q.front();
					Q.pop();
					FORR(c,C) {
						y=mult[cur][c];
						if(did[y]==0) {
							num++;
							did[y]=1;
							Q.push(y);
						}
					}
				}
			}
			
		}
		ret+=(N-pre)*num;
		
	}
	cout<<ret<<endl;
	
}
 
 
int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}