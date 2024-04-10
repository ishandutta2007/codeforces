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

int N,M,K;
int A[202020],B[202020];
map<int,int> MP[202020];

int D[202020];
vector<int> E[202020];
vector<int> cand[202020];

int ret[202020];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>K;
	FOR(i,M) {
		cin>>A[i]>>B[i];
		A[i]--,B[i]--;
		MP[A[i]][B[i]]=i;
		MP[B[i]][A[i]]=i;
		E[A[i]].push_back(B[i]);
		E[B[i]].push_back(A[i]);
	}
	
	FOR(i,N) D[i]=202020;
	D[0]=0;
	queue<int> Q;
	Q.push(0);
	while(Q.size()) {
		x=Q.front();
		Q.pop();
		FORR(e,E[x]) if(D[e]>D[x]+1) D[e]=D[x]+1, Q.push(e);
	}
	
	ll pat=1;
	FOR(i,N) {
		FORR(e,E[i]) if(D[e]<D[i]) cand[i].push_back(e);
		if(i) pat=min((ll)K,pat*(ll)cand[i].size());
	}
	
	cout<<pat<<endl;
	FOR(i,pat) {
		ll cur=i;
		ZERO(ret);
		FOR(x,N) if(cand[x].size()) {
			y=cur%cand[x].size();
			cur/=cand[x].size();
			ret[MP[x][cand[x][y]]]=1;
		}
		
		FOR(x,M) cout<<ret[x];
		cout<<endl;
		
	}
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}