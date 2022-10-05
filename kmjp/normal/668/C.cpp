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
long double ma[101010];
long double mi[101010];

long double P[2][101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>ma[i];
	FOR(i,N) cin>>mi[i];
	long double a=0,b=0;
	FOR(i,N) {
		long double na=1-a;
		long double nb=1-b;
		
		long double MM=ma[i]+mi[i];
		long double BB=-(a-b+MM);
		long double CC=-(MM*b-ma[i]);
		long double D=sqrt(max(BB*BB-4*CC,(long double)0.0));
		
		P[1][i]=min(max((long double)0.0,(-BB+D)/2),(long double)1.0);
		P[0][i]=min(max((long double)0.0,MM-P[1][i]),(long double)1.0);
		
		a+=P[0][i];
		b+=P[1][i];
	}
	FOR(i,N) _P("%.12lf%s",(double)P[0][i],(i==N-1)?"\n":" ");
	FOR(i,N) _P("%.12lf%s",(double)P[1][i],(i==N-1)?"\n":" ");
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}