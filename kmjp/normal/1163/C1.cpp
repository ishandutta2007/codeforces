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
int X[1010],Y[1010];
set<int> vert,hori;
map<pair<ll,ll>,set<pair<ll,ll>>> M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>X[i]>>Y[i];
	
	FOR(j,N) FOR(i,j) {
		if(X[i]==X[j]) {
			M[{0,0}].insert({X[i],1});
		}
		else if(Y[i]==Y[j]) {
			M[{0,1}].insert({Y[i],1});
		}
		else {
			ll dx=X[j]-X[i];
			ll dy=Y[j]-Y[i];
			ll g=__gcd(dx,dy);
			dx/=g;
			dy/=g;
			if(dx<0) dx=-dx,dy=-dy;
			ll p=Y[i]*dx-dy*X[i];
			ll q=dx;
			g=__gcd(p,q);
			p/=g;
			q/=g;
			M[{dy,dx}].insert({p,q});
		}
	}
	
	ll S=0;
	ll ret=0;
	FORR(m,M) {
		ret+=S*m.second.size();
		S+=m.second.size();
	}
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}