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
ll B,Q,Y;
ll C,R,Z;
const ll mo=1000000007;
ll hoge() {
	int i,j,k,l,r,x,y; string s;
	ll BR=B+Q*(Y-1);
	ll CR=C+R*(Z-1);

	if(C<B||C>BR) return 0;
	if(CR<B||CR>BR) return 0;
	if((C-B)%Q) return 0;
	if((CR-B)%Q) return 0;

	if(Z==1) {
		return -1;
	}
	
	if(R%Q) return 0;
	if(C-R<B||CR+R>BR) return -1;
	
	vector<int> Gs;
	for(int g=1;g*g<=Q;g++) if(Q%g==0) {
		Gs.push_back(g);
		if(g*g!=Q) Gs.push_back(Q/g);
	}
	set<int> Ps;
	FORR(g,Gs) {
		ll p=1LL*R*g/Q;
		if(__gcd(p,Q)==g&&p*Q/g==R) Ps.insert(p);
	}
	
	ll ret=0;
	
	FORR(P,Ps) {
		ll a=R/P;
		(ret+=a*a)%=mo;
	}
	
	
	return ret;
	
}

void solve() {
	
	cin>>T;
	while(T--) {
		cin>>B>>Q>>Y;
		cin>>C>>R>>Z;
		
		cout<<hoge()<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}