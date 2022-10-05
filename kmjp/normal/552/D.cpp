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
int X[2010],Y[2010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	ll ret=0;
	FOR(x,N) {
		map<pair<int,int>,int> M;
		FOR(y,N) if(x!=y) {
			int dx=X[y]-X[x],dy=Y[y]-Y[x];
			if(dx==0) dy=1;
			else if(dy==0) dx=1;
			else {
				int g=__gcd(abs(dx),abs(dy));
				dx/=g, dy/=g;
				if(dx<0) dx=-dx,dy=-dy;
			}
			M[make_pair(dx,dy)]++;
		}
		ret += (N-1)*(N-2)/2;
		FORR(r,M) ret -= (r.second)*(r.second-1)/2;
	}
	
	
	cout<<ret/3<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}