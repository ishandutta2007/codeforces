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


typedef __int128 lll;
int N;
string S;
int MSB;
lll V;

lll mul(lll a,lll b) {
	// a*b%V
	lll c=0;
	int i;
	FOR(i,MSB+2) if(a&(1LL<<i)) c^=b<<i;
	for(i=MSB*2+2;i>=MSB;i--) if(c&(((lll)1)<<i)) c^=V<<(i-MSB);
	return c;
}

ll hoge(lll a) {
	// (V*2^a)%V==1?
	lll c=1;
	lll c2=2;
	int i;
	FOR(i,60) {
		if(a&(1LL<<i)) c=mul(c,c2);
		c2=mul(c2,c2);
	}
	return (ll)c;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>S;
	N=S.size();
	int pad=1;
	while(S.size()&&S[0]=='0') N--,pad++,S.erase(S.begin());
	if(N==0) {
		cout<<-1<<endl;
		return;
	}
	while(S.back()=='0') S.pop_back(),N--;
	
	vector<int> P;
	FOR(i,N) if(S[i]=='1') P.push_back(i);
	if(P.size()==1) {
		cout<<pad<<" "<<pad+1<<endl;
		return;
	}
	if(P.size()==2) {
		cout<<pad<<" "<<pad+P[1]<<endl;
		return;
	}
	
	reverse(ALL(S));
	FORR(c,S) V=V*2+c-'0';
	FOR(i,40) if(V&(1LL<<i)) MSB=i;
	
	map<ll,int> M;
	ll ret=1LL<<50;
	ll cur=1;
	FOR(i,1<<17) {
		M[cur]=i;
		if(i&&cur==1) ret=min(ret,(ll)i);
		cur=mul(cur,2);
	}
	ll m=cur;
	
	for(i=1;i<=1<<17;i++) {
		if(M.count(cur)) ret=min(ret,((1LL*i)<<17)-M[cur]);
		cur=mul(cur,m);
	}
	
	cout<<pad<<" "<<pad+ret<<endl;
	
	
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}