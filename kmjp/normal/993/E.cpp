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

vector<Comp> MultPoly(vector<Comp> P,vector<Comp> Q,bool resize=false) {
	if(resize) {
		int maxind=0,pi=0,qi=0,i;
		int s=2;
		FOR(i,P.size()) if(norm(P[i])) pi=i;
		FOR(i,Q.size()) if(norm(Q[i])) qi=i;
		maxind=pi+qi+1;
		while(s*2<maxind) s*=2;
		P.resize(s*2);Q.resize(s*2);
	}
	P=fft(P), Q=fft(Q);
	for(int i=0;i<P.size();i++) P[i]*=Q[i];
	return fft(P,true);
}

int N;
int X;
int A[202020];
ll ret[202020];
vector<int> LV,RV;
vector<Comp> LC,RC;
vector<Comp> AV;


void dfs(int L,int R) {
	int i;
	if(R-L<=400) {
		while(L<R) {
			int x=0;
			for(i=L;i<R;i++) {
				x+=A[i];
				ret[x]++;
			}
			L++;
		}
		return;
	}
	LV.resize(1);
	RV.resize(1);
	LV[0]=1;
	RV[0]=1;
	int M=(R+L)/2;
	for(i=M+1;i<R;i++) {
		if(A[i]) RV.push_back(0);
		RV.back()++;
	}
	for(i=M-1;i>=L;i--) {
		if(A[i]) LV.push_back(0);
		LV.back()++;
	}
	LC.clear();
	RC.clear();
	FORR(c,LV) LC.push_back(c);
	FORR(c,RV) RC.push_back(c);
	
	
	AV=MultPoly(LC,RC,true);
	FOR(i,AV.size()) ret[A[M]+i] += (ll)(AV[i].real()+0.1);
	
	dfs(L,M);
	dfs(M+1,R);
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>X;
	FOR(i,N) {
		cin>>A[i];
		A[i]=A[i]<X;
	}
	dfs(0,N);
	
	
	FOR(i,N+1) cout<<ret[i]<<" ";
	cout<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}