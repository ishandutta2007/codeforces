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

int N,M;
int X[1010];
int tot;
double from[1010100],to[1010100],sfrom[2010100];
const int SL=100002;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	
	if(M==1) return _P("1\n");
	
	double rev=1/(M-1.0);
	
	from[SL]=M-1;
	FOR(i,N) {
		cin>>X[i], tot+=X[i];
		FOR(x,100011) {
			sfrom[SL+x]=sfrom[SL+x-1]+from[SL+x];
			to[SL+x] = sfrom[SL+x-1] - sfrom[SL+(x-M-1)] - from[SL+x-X[i]];
			to[SL+x] *= rev;
		}
		swap(from,to);
	}
	
	double ret=1;
	FOR(i,tot) ret+=from[SL+i];
	_P("%.12lf\n",ret);
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}