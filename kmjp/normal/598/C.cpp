#include <bits/stdc++.h>
using namespace std;
typedef signed long long ll;

#undef _P
#define _P(...) (void)printf(__VA_ARGS__)
#define FOR(x,to) for(x=0;x<to;x++)
#define FORR(x,arr) for(auto& x:arr)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ALL(a) (a.begin()),(a.end())
#define ZERO(a) memset(a,0,sizeof(a))
#define MINUS(a) memset(a,0xff,sizeof(a))
//-------------------------------------------------------

int N;
int X[101010],Y[101010];
pair<long double,int> P[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) {
		cin>>X[i]>>Y[i];
		P[i]=make_pair(atan2l(Y[i],X[i]),i);
	}
	sort(P,P+N);
	P[N]=P[0];
	P[N].first+=2*atan(1)*4;
	
	long double mi=1010;
	FOR(i,N) if(P[i+1].first-P[i].first<mi) {
		mi=P[i+1].first-P[i].first;
		x=P[i+1].second;
		y=P[i].second;
	}
	_P("%d %d\n",x+1,y+1);
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}