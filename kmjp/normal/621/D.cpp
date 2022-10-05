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

long double X,Y,Z;

string S[13]= {
	"",
	"x^y^z",
	"x^z^y",
	"(x^y)^z",
	"(x^z)^y",
	"y^x^z",
	"y^z^x",
	"(y^x)^z",
	"(y^z)^x",
	"z^x^y",
	"z^y^x",
	"(z^x)^y",
	"(z^y)^x",
};

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>X>>Y>>Z;
	pair<long double, int> P[9];
	P[0]={-log(X)*pow(Y,Z),1};
	P[1]={-log(X)*pow(Z,Y),2};
	P[2]={-log(X)*(Y*Z),3};
	P[3]={-log(Y)*pow(X,Z),5};
	P[4]={-log(Y)*pow(Z,X),6};
	P[5]={-log(Y)*(X*Z),7};
	P[6]={-log(Z)*pow(X,Y),9};
	P[7]={-log(Z)*pow(Y,X),10};
	P[8]={-log(Z)*(X*Y),11};
	sort(P,P+9);
	cout<<S[P[0].second]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}