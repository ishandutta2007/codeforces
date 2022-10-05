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
double L[1010101],R[1010101];
int X[101010],V[101010],T[101010];

int LL[1010000],RR[1010000];

int ok(double TT) {
	ZERO(LL);
	ZERO(RR);
	
	int i;
	FOR(i,N) {
		if(T[i]==1) {
			if(X[i]*1.0/V[i]-1e-9<=TT) LL[0]++;
			else if(X[i]*1.0/(S+V[i])-1e-9<=TT) {
				LL[X[i]]++;
				double a=TT*(V[i]+S)-X[i];
				double y=a*(S-V[i])/S;
				
				LL[min(1000001LL,X[i]+(ll)floor(y)+1)]--;
			}
		}
		else {
			if((1000000-X[i])*1.0/V[i]-1e-9<=TT) RR[1000000]++;
			else if((1000000-X[i])*1.0/(S+V[i])-1e-9<=TT) {
				RR[X[i]]++;
				double a=TT*(V[i]+S)-(1000000-X[i]);
				double y=a*(S-V[i])/S;
				if(X[i]-floor(y)-1>=0) RR[X[i]-(ll)floor(y)-1]--;
			}
		}
	}
	for(i=1;i<=1000000;i++) LL[i]+=LL[i-1];
	for(i=1000000;i>=0;i--) RR[i]+=RR[i+1];
	FOR(i,1000001) if(LL[i]&&RR[i]) return 1;
	return 0;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>S;
	FOR(i,N) cin>>X[i]>>V[i]>>T[i];
	
	double L=0,R=1e6;
	FOR(i,60) {
		double M=(L+R)/2;
		if(ok(M)) R=M;
		else L=M;
	}
	
	_P("%.12lf\n",L);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}