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

typedef complex<double> Comp;

vector<Comp> fft(vector<Comp> v, bool rev=false) {
	int n=v.size(),i,j,m;
	
	for(i=0,j=1;j<n-1;j++) {
		for(int k=n>>1;k>(i^=k);k>>=1);
		if(i>j) swap(v[i],v[j]);
	}
	for(int m=2; m<=n; m*=2) {
		double deg=(rev?-1:1) * 2*acos(-1)/m;
		Comp wr(cos(deg),sin(deg));
		for(i=0;i<n;i+=m) {
			Comp w(1,0);
			for(int j1=i,j2=i+m/2;j2<i+m;j1++,j2++) {
				Comp t1=v[j1],t2=w*v[j2];
				v[j1]=t1+t2, v[j2]=t1-t2;
				w*=wr;
			}
		}
	}
	if(rev) FOR(i,n) v[i]*=1.0/n;
	return v;
}

vector<Comp> MultPoly(vector<Comp> P,vector<Comp> Q) {
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

int T,N;
string S;
int NG[505050];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>S;
		
		int L=1;
		while(L<=2*N) L*=2;
		vector<Comp> VA(L,0),KA(L,0),VB(L,0),KB(L,0);
		FOR(i,N) {
			if(S[i]=='V') VA[i]=VB[N-1-i]=1;
			if(S[i]=='K') KA[i]=KB[N-1-i]=1;
		}
		auto A=MultPoly(VA,KB);
		auto B=MultPoly(KA,VB);
		
		FOR(i,N+1) NG[i]=0;
		int cnt=1;
		for(i=N-1;i>=1;i--) {
			if((int)(A[N-1-i].real()+0.2)>0 || (int)(B[N-1-i].real()+0.2)>0) NG[i]=1;
			for(j=i*2;j<=N;j+=i) NG[i] |= NG[j];
			if(NG[i]==0) cnt++;
		}
		
		_P("%d\n",cnt);
		for(i=1;i<=N;i++) if(NG[i]==0) _P("%d%c",i,(i==N)?'\n':' ');
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n';
	FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	solve(); return 0;
}