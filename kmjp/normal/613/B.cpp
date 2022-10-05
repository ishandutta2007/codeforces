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

ll N,AA,CF,CM,M;
pair<ll,int> A[101010];
ll S[101010];
int R[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>AA>>CF>>CM>>M;
	FOR(i,N) cin>>A[i].first, A[i].second=i;
	
	sort(A,A+N);
	FOR(i,N) S[i+1]=S[i]+A[i].first;
	
	int mi=0,ma=0;
	ll lvv=0;
	ll V=0;
	if(N*AA-S[N]<=M) {
		V=N*CF+AA*CM;
		mi=0,ma=N;
	}
	else {
		y=N;
		for(x=N;x>=0;x--) {
			if(x<N) {
				M-=AA-A[x].first;
				if(M<0) break;
			}
			while(y*A[y-1].first-S[y]>M) y--;
			y=min(y,x);
			ll left=M-(y*A[y-1].first-S[y]);
			ll lv=min(A[y-1].first+left/y,AA);
			ll sc=(N-x)*CF+lv*CM;
			if(sc>V) {
				V=sc;
				mi=y;
				ma=N-x;
				lvv=lv;
			}
		}
	}
	
	cout<<V<<endl;
	FOR(i,N)  R[A[i].second]=A[i].first;
	FOR(i,mi) R[A[i].second]=lvv;
	FOR(i,ma) R[A[N-1-i].second]=AA;
	FOR(i,N) {
		cout<<R[i];
		if(i<N-1) cout<<" ";
	}
	cout<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}