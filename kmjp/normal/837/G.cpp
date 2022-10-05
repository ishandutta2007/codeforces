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
int X1[101010],X2[101010],Y1[101010],A[101010],B[101010],Y2[101010];
int Q;
int L,R,X;
vector<int> MP;
const int DI=500;
ll BB[203030][75000/DI+5];
int AA[203030][75000/DI+5];

ll val(int i,int x) {
	if(x<=X1[i]) return Y1[i];
	if(x>X2[i]) return Y2[i];
	return (ll)A[i]*x+B[i];
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	scanf("%d",&N);
	MP.push_back(0);
	FOR(i,N) {
		scanf("%d%d%d%d%d%d",&X1[i],&X2[i],&Y1[i],&A[i],&B[i],&Y2[i]);
		MP.push_back(X1[i]+1);
		MP.push_back(X2[i]+1);
	}
	MP.push_back(1000000001);
	sort(ALL(MP));
	MP.erase(unique(ALL(MP)),MP.end());
	FOR(i,N) {
		y=i/DI;
		BB[0][y]+=Y1[i];
		x=lower_bound(ALL(MP),X1[i]+1)-MP.begin();
		BB[x][y]+=B[i]-Y1[i];
		AA[x][y]+=A[i];
		x=lower_bound(ALL(MP),X2[i]+1)-MP.begin();
		BB[x][y]+=Y2[i]-B[i];
		AA[x][y]-=A[i];
	}
	FOR(i,N/DI+1) for(x=1;x<MP.size();x++) AA[x][i]+=AA[x-1][i],BB[x][i]+=BB[x-1][i];
	
	scanf("%d",&Q);
	ll last=0;
	while(Q--) {
		scanf("%d%d%d",&L,&R,&X);
		L--,R--;
		X=(X+last)%1000000000;
		
		last=0;
		while(R%DI!=DI-1 && L<=R) last+=val(R,X),R--;
		while(L%DI!=0 && L<=R) last+=val(L,X),L++;
		x=lower_bound(ALL(MP),X+1)-MP.begin()-1;
		while(R>L) last+=(ll)AA[x][R/DI]*X+BB[x][R/DI],R-=DI;
		_P("%" PRId64 "\n",last);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}