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
ll X[101010],Y[101010];
pair<ll,ll> P[101010];
ll Lmiy[101010],Lmay[101010];
ll Rmiy[101010],Rmay[101010];

int ok(ll v) {
	int L,R;
	
	R=0;
	FOR(L,N) {
		if(X[L]>0) break;
		ll ri=min(-X[L],X[L]+(ll)sqrt(v+1e-8));
		while(R+1<N && X[R+1] <= ri) R++;
		while(X[R] > ri) R--;
		
		ll miy=min(Rmiy[R+1],Lmiy[L]);
		ll may=max(Rmay[R+1],Lmay[L]);
		ll ma=max(may,-miy);
		if(max((may-miy)*(may-miy),X[L]*X[L]+ma*ma)<=v) return 1;
		
	}
	L=N-1;
	for(R=N-1;R>=0;R--) {
		if(X[R]<0) break;
		ll le=max(-X[R],X[R]-(ll)sqrt(v+1e-8));
		while(L>0 && X[L-1] >= le ) L--;
		while(X[L] < le) L++;
		
		ll miy=min(Rmiy[R+1],Lmiy[L]);
		ll may=max(Rmay[R+1],Lmay[L]);
		ll ma=max(may,-miy);
		if(max((may-miy)*(may-miy),X[R]*X[R]+ma*ma)<=v) return 1;
	}
	return 0;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	FOR(i,N) cin>>P[i].first>>P[i].second;
	sort(P,P+N);
	FOR(i,N) X[i]=P[i].first,Y[i]=P[i].second;
	
	FOR(i,N) {
		Lmay[i+1]=max(Lmay[i],Y[i]);
		Lmiy[i+1]=min(Lmiy[i],Y[i]);
	}
	for(i=N-1;i>=0;i--) {
		Rmay[i]=max(Rmay[i+1],Y[i]);
		Rmiy[i]=min(Rmiy[i+1],Y[i]);
	}
	
	ll ret=(1LL<<60)-1;
	for(i=59;i>=0;i--) if(ok(ret-(1LL<<i))) ret-=1LL<<i;
	ll mixx=*min_element(X,X+N);
	ll maxx=*max_element(X,X+N);
	ll miyy=*min_element(Y,Y+N);
	ll mayy=*max_element(Y,Y+N);
	ret=min(ret,(maxx-mixx)*(maxx-mixx));
	ret=min(ret,(mayy-miyy)*(mayy-miyy));
	
	cout<<ret<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}