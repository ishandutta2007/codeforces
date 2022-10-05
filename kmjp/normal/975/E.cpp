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
long double X[10101],Y[10101];
long double A[10101];
long double R[10101];
long double SX=0,SY=0;
long double D;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>Q;
	for(i=1;i<=N;i++) {
		cin>>X[i]>>Y[i];
	}
	
	double SA=0;
	for(i=2;i<N;i++) {
		double px=(X[1]+X[i]+X[i+1])/3.0;
		double py=(Y[1]+Y[i]+Y[i+1])/3.0;
		double a=abs((X[i]-X[1])*(Y[i+1]-Y[1])-(X[i+1]-X[1])*(Y[i]-Y[1]));
		SX+=a*px;
		SY+=a*py;
		SA+=a;
	}
	SX/=SA;
	SY/=SA;
	
	for(i=1;i<=N;i++) {
		R[i]=hypot(X[i]-SX,Y[i]-SY);
		A[i]=atan2(Y[i]-SY,X[i]-SX);
		while(A[i]<A[i-1]) A[i]+=atan(1)*8;
	}
	
	int P[2]={1,2};
	long double PX[2]={X[1],X[2]};
	long double PY[2]={Y[1],Y[2]};
	
	
	while(Q--) {
		cin>>k;
		if(k==1) {
			int f,t;
			cin>>f>>t;
			if(P[0]==f) i=1, P[0]=t;
			else i=0, P[1]=t;
			SX=PX[i];
			SY=PY[i]-R[P[i]];
			D=atan(1)*2-A[P[i]];
			PX[i^1]=SX+R[t]*cos(D+A[t]);
			PY[i^1]=SY+R[t]*sin(D+A[t]);
			
		}
		else {
			cin>>i;
			long double px=SX+R[i]*cos(D+A[i]);
			long double py=SY+R[i]*sin(D+A[i]);
			_P("%.12lf %.12lf\n",(double)px,(double)py);
			
		}
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}