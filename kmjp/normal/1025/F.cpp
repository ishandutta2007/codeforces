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
double X[2020],Y[2020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	ll ret=0;
	FOR(i,N) {
		vector<double> V;
		FOR(j,N) if(i!=j) V.push_back(atan2(Y[j]-Y[i],X[j]-X[i])), V.push_back(atan2(Y[j]-Y[i],X[j]-X[i])+2*atan(1)*4);
		sort(ALL(V));
		for(x=y=0;x<N-1;x++) {
			while(V[y]-V[x]<atan(1)*4) y++;
			j=y-x-1;
			r=N-2-j;
			ret+=(ll)j*(j-1)/2*r*(r-1)/2;
		}
	}
	cout<<ret/2<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}