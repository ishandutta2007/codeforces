#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<(to);x++)
#define FORR(x,arr) for(auto& x:arr)
#define FORR2(x,y,arr) for(auto& [x,y]:arr)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
template<class T> bool chmax(T &a, const T &b) { if(a<b){a=b;return 1;}return 0;}
template<class T> bool chmin(T &a, const T &b) { if(a>b){a=b;return 1;}return 0;}
//-------------------------------------------------------


int T;
double C,M,P,V;

map<pair<double,double>,double> memo;

double hoge(double C,double M) {
	double P=1;
	if(C<1e-9) C=0;
	if(M<1e-9) M=0;
	
	if(C>=0) P-=C;
	if(M>=0) P-=M;
	
	double ret=P;
	if(C>0) {
		if(M<=0) ret+=C*(1+hoge(C-V,0));
		else ret+=C*(1+hoge(C-V,M+min(C,V)/2));
	}
	if(M>0) {
		if(C<=0) ret+=M*(1+hoge(0,M-V));
		else ret+=M*(1+hoge(C+min(M,V)/2,M-V));
	}
	return ret;
	
	
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>C>>M>>P>>V;
		memo.clear();
		double a=hoge(C,M);
		
		_P("%.12lf\n",a);
		
	}
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}