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
ll M,T;
int S[303030],NS[303030],ret[303030];
int D[303030];
int O[303030];
int NL,NR;
pair<int,int> P[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M>>T;
	vector<int> VL,VR;
	FOR(i,N) {
		cin>>S[i]>>s;
		S[i]--;
		D[i]=s[0]=='R';
		if(D[i]==0) {
			NL++;
			VL.push_back(S[i]),VL.push_back(S[i]+M);
			NS[i]=(M+(S[i]-T)%M)%M;
		}
		else {
			NR++;
			VR.push_back(S[i]),VR.push_back(S[i]+M);
			NS[i]=(S[i]+T)%M;
		}
		
		P[i]={S[i],i};
	}
	
	if(NL==0 || NR==0) {
		FOR(i,N) _P("%d ",NS[i]+1);
		_P("\n");
		return;
	}
	
	sort(P,P+N);
	FOR(i,N) O[P[i].second]=i;
	sort(ALL(VL));
	sort(ALL(VR));
	
	FOR(i,N) {
		x=P[i].second;
		if(D[x]==0) {
			ll col=2*T/M*NR;
			int left=(int)(2*T%M);
			auto it1=lower_bound(ALL(VR),S[x]+M);
			auto it2=lower_bound(ALL(VR),S[x]+M-left);
			col += it1-it2;
			y = (N+(i-col)%N)%N;
		}
		else {
			ll col=2*T/M*NL;
			int left=(int)(2*T%M);
			auto it1=lower_bound(ALL(VL),S[x]+left+1);
			auto it2=lower_bound(ALL(VL),S[x]);
			col += it1-it2;
			y = (i+col)%N;
		}
		ret[P[y].second] = NS[x]+1;
		
	}
	
	FOR(i,N) _P("%d ",ret[i]);
	_P("\n");
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}