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


int T;
int N;

void solve() {
	int i,j,k,l,r,x,y; string s;
	double pi=atan(1)*4;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		double ret=0;
		if(N%2==0) {
			double d=pi/N;
			FOR(i,N) ret+=sin(i*d);
		}
		else {
			double d=pi/N;
			double r=0.5/sin(d/2);
			cout<<r<<endl;
			double c=r*cos(d);
			double s=r*sin(d);
			cout<<c<<" "<<s<<endl;
			ret=2*(c+s)/sqrt(2);
		}
		_P("%.12lf\n",ret);
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}