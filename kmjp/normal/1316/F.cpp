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
ll P[603030];
int X[603030];
int las[303030];
const ll mo=1000000007;
int id[606060];
pair<int,int> S[606060];

ll p2[603030];
ll r2[603030];

int rev2=(mo+1)/2;

const int NV=1<<20;
vector<ll> val[NV*2];
int Q;

void comp(vector<ll>& A,vector<ll>& B,vector<ll>& C) {
	if(A[3]==0) {
		C=B;
	}
	else if(B[3]==0) {
		C=A;
	}
	else {
		C[3]=A[3]+B[3];
		C[0]=(A[0]+B[0]+A[2]*B[1])%mo;
		C[1]=(A[1]+B[1]*r2[A[3]])%mo;
		C[2]=(B[2]+A[2]*r2[B[3]])%mo;
	}
}

void update(int entry, vector<ll> v) {
	entry += NV;
	val[entry]=v;
	while(entry>1) entry>>=1, comp(val[entry*2],val[entry*2+1],val[entry]);
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	p2[0]=r2[0]=1;
	FOR(i,601010) p2[i+1]=p2[i]*2%mo;
	FOR(i,601010) r2[i+1]=r2[i]*rev2%mo;
	
	MINUS(las);
	
	FOR(i,NV*2) val[i]={0,0,0,0};
	
	
	scanf("%d",&N);
	FOR(i,N) {
		scanf("%d",&x);
		X[i]=i;
		P[i]=x;
	}
	scanf("%d",&Q);
	FOR(i,Q) {
		scanf("%d%d",&x,&y);
		X[N+i]=x-1;
		P[N+i]=y;
	}
	
	FOR(i,N+Q) S[i]={P[i],i};
	sort(S,S+N+Q);
	
	FOR(i,N+Q) id[S[i].second]=i;
	FOR(i,N+Q) {
		x=X[i];
		y=las[x];
		if(y>=0) update(y,{0,0,0,0});
		y=las[x]=id[i];
		update(y,{0,P[i]*rev2%mo,P[i]*rev2%mo,1});
		
		if(i>=N-1) _P("%d\n",(int)(val[1][0]));
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}