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
ll X[1010][2],Y[1010][2];
ll ret;
map<pair<int,int>,set<int>> M;

typedef complex<double> Po;
struct Line {
	Po a,b;
	void Rep(){
		// assert(a!=b);
		if(a.real()==b.real()) { a.imag(0);b.imag(1); return;} // Y-axis
		Po c,d;
		d.real(1);
		d.imag((b.imag()-a.imag())/(b.real()-a.real()));
		c.imag(b.imag()-b.real()*d.imag());
		d.imag(d.imag()+c.imag());
		a=c; b=d;
	};
};


Po CrossPoint(const Line &l,const Line &r) {
	Po p,ld=l.b-l.a,rd=r.b-r.a,d3=l.b-r.a;
	double aa=ld.real()*rd.imag()-ld.imag()*rd.real();
	double bb=ld.real()*d3.imag()-ld.imag()*d3.real();
	if(abs(aa)<1e-9 && abs(bb)<1e-9) return Po(1e9,-1e9); //same
	if(abs(aa)<1e-9) return Po(1e9,1e9); //parallel
	return r.a+bb/aa*(r.b-r.a);
};

Line L[1010];

	
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i][0]>>Y[i][0]>>X[i][1]>>Y[i][1];
		L[i].a.real(X[i][0]);
		L[i].a.imag(Y[i][0]);
		L[i].b.real(X[i][1]);
		L[i].b.imag(Y[i][1]);
		L[i].Rep();
		
		ll a=abs(X[i][1]-X[i][0]);
		ll b=abs(Y[i][1]-Y[i][0]);
		ret+=1+__gcd(a,b);
	}
	FOR(i,N) FOR(j,i) {
		Po p=CrossPoint(L[i],L[j]);
		double x=p.real(),y=p.imag();
		ll xa=round(x);
		ll ya=round(y);
		if(xa<X[i][0]&&xa<X[i][1]) continue;
		if(xa>X[i][0]&&xa>X[i][1]) continue;
		if(ya<Y[i][0]&&ya<Y[i][1]) continue;
		if(ya>Y[i][0]&&ya>Y[i][1]) continue;
		if(xa<X[j][0]&&xa<X[j][1]) continue;
		if(xa>X[j][0]&&xa>X[j][1]) continue;
		if(ya<Y[j][0]&&ya<Y[j][1]) continue;
		if(ya>Y[j][0]&&ya>Y[j][1]) continue;
		if((xa-X[i][0])*(Y[i][1]-Y[i][0])-(X[i][1]-X[i][0])*(ya-Y[i][0])) continue;
		if((xa-X[j][0])*(Y[j][1]-Y[j][0])-(X[j][1]-X[j][0])*(ya-Y[j][0])) continue;
		M[{xa,ya}].insert(i);
		M[{xa,ya}].insert(j);
	}
	
	FORR(m,M) ret-=m.second.size()-1;
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}