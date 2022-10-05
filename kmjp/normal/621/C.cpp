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
ll P;
int L[101010],R[101010];
double H[301010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	FOR(i,N) {
		cin>>L[i]>>R[i];
		H[i+N]=H[i]=(R[i]/P-(L[i]-1)/P)*1.0/(R[i]-L[i]+1);
	}
	
	double ret=0;
	FOR(i,N) {
		double p=1-(1-H[i])*(1-H[i+1]);
		ret += 2000*p;
	}
	_P("%.12lf\n",ret);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}