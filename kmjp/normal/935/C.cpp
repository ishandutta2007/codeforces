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

double R;
double X[2],Y[2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>R>>X[0]>>Y[0]>>X[1]>>Y[1];
	
	if((X[0]-X[1])*(X[0]-X[1])+(Y[0]-Y[1])*(Y[0]-Y[1])>=R*R) {
		cout<<X[0]<<" "<<Y[0]<<" "<<R<<endl;
	}
	else if(X[0]==X[1] && Y[0]==Y[1]) {
		_P("%.12lf %.12lf %.12lf\n",X[0]+R/2.0,Y[0],R/2.0);
	}
	else {
		double dx=X[0]-X[1];
		double dy=Y[0]-Y[1];
		double d=hypot(dx,dy);
		dx/=d;
		dy/=d;
		double tx=X[0]+dx*(2*R-(R+d))/2.0;
		double ty=Y[0]+dy*(2*R-(R+d))/2.0;
		_P("%.12lf %.12lf %.12lf\n",tx,ty,(R+d)/2.0);
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}