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
int P[303030];
char C[303030];

ll hoge(int L,int R) {
	
	vector<int> D[2];
	int pr=L,pb=L;
	int mar=0,mab=0;
	int i;
	for(i=L+1;i<R;i++) {
		if(C[i]=='R') {
			mar=max(mar,P[i]-P[pr]);
			pr=i;
		}
		else {
			mab=max(mab,P[i]-P[pb]);
			pb=i;
		}
	}
	mar=max(mar,P[R]-P[pr]);
	mab=max(mab,P[R]-P[pb]);
	return min(2*(P[R]-P[L]),3*(P[R]-P[L])-mar-mab);
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int gmi=N,gma=-1;
	int rmi=N,rma=-1;
	int bmi=N,bma=-1;
	FOR(i,N) {
		cin>>P[i]>>C[i];
		if(C[i]=='G') gmi=min(gmi,i),gma=max(gma,i);
		if(C[i]=='B') bmi=min(bmi,i),bma=max(bma,i);
		if(C[i]=='R') rmi=min(rmi,i),rma=max(rma,i);
	}
	ll ret=0;
	if(gma==-1) {
		if(rma>=0) ret+=P[rma]-P[rmi];
		if(bma>=0) ret+=P[bma]-P[bmi];
	}
	else {
		if(rma>gma) ret+=P[rma]-P[gma];
		if(bma>gma) ret+=P[bma]-P[gma];
		if(rmi<gmi) ret+=P[gmi]-P[rmi];
		if(bmi<gmi) ret+=P[gmi]-P[bmi];
		for(i=gmi+1;i<=gma;i++) {
			if(C[i]=='G') {
				ret+=hoge(gmi,i);
				gmi=i;
			}
		}
	}
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}