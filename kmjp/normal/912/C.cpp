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

int N,M;
int B,I,D;
int MH[101010],R[101010];
vector<pair<ll,int>> V[101010];
int T,E,H;

map<ll,int> C;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d%d",&N,&M);
	scanf("%d%d%d",&B,&I,&D);
	FOR(i,N) {
		scanf("%d%d%d",&MH[i],&x,&R[i]);
		V[i].push_back({0,x});
		V[i].push_back({1LL<<40,1LL<<40});
	}
	FOR(i,M) {
		scanf("%d%d%d",&T,&E,&H);
		V[E-1].push_back({T,H});
	}
	
	C[1LL<<40]=0;
	FOR(i,N) {
		sort(ALL(V[i]));
		FOR(j,V[i].size()-1) if(V[i][j].second<=D) {
			C[V[i][j].first]++;
			ll ma=V[i][j+1].first;
			if(R[i] && MH[i]>D) ma=min(ma,(ll)V[i][j].first + (D+1-V[i][j].second+(R[i]-1))/R[i]);
			C[ma]--;
		}
	}
	
	ll ret=0;
	int cnt=0;
	FORR(m,C) {
		if(m.first==1LL<<40) {
			if(I && cnt) ret=-1;
			else ret=max(ret,1LL*cnt*B);
			break;
		}
		if(m.first) ret=max(ret,1LL*cnt*(B+(m.first-1)*I));
		cnt+=m.second;
	}
	cout<<ret<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}