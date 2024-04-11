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


int N,Q;
string S;

const int NP=5;
struct mat { int x[NP][NP];};

const int NV=1<<18;
mat val[NV*2],def,ze;

mat conv(const mat& b,const mat& c) {
	mat a=def;
	int i,j,k;
	FOR(i,NP) for(k=i;k<NP;k++) for(j=k;j<NP;j++) a.x[i][j]=min(a.x[i][j],b.x[i][k]+c.x[k][j]);
	return a;
}

mat getval(int x,int y,int l=0,int r=NV,int k=1) { // x<=i<y
	if(r<=x || y<=l) return ze;
	if(x<=l && r<=y) return val[k];
	return conv(getval(x,y,l,(l+r)/2,k*2) ,getval(x,y,(l+r)/2,r,k*2+1));
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q>>S;
	FOR(i,NP) FOR(j,NP) def.x[i][j]=1<<28;
	ze = def;
	FOR(i,NP) ze.x[i][i]=0;
	FOR(i,NV) val[i+NV]=ze;
	
	FOR(i,N) {
		if(S[i]=='2') {
			val[i+NV+1].x[0][0]=1;
			val[i+NV+1].x[0][1]=0;
		}
		else if(S[i]=='0') {
			val[i+NV+1].x[1][1]=1;
			val[i+NV+1].x[1][2]=0;
		}
		else if(S[i]=='1') {
			val[i+NV+1].x[2][2]=1;
			val[i+NV+1].x[2][3]=0;
		}
		else if(S[i]=='7') {
			val[i+NV+1].x[3][4]=0;
		}
		else if(S[i]=='6') {
			val[i+NV+1].x[3][3]=1;
			val[i+NV+1].x[4][4]=1;
		}
	}
	
	for(i=NV-1;i>=1;i--) val[i]=conv(val[i*2],val[i*2+1]);
	FOR(i,Q) {
		int A,B;
		cin>>A>>B;
		auto v=getval(A,B+1).x[0][4];
		if(v>=1<<28) v=-1;
		_P("%d\n",v);
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}