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

int N,M;
int A[201010];
vector<vector<int>> event;
vector<vector<int>> update;
int ret[201010];
const int DI=2222;

int C[201010];
int ord[201010];
int L[201010],R[201010];

void inc(int v) {
	int pos=L[C[v]]++;
	ord[pos]++;
	C[v]++;
	if(L[C[v]]==R[C[v]]) {
		L[C[v]]=pos;
		R[C[v]]=pos+1;
	}
	else {
		R[C[v]]=pos+1;
	}
}

void del(int v) {
	int pos=--R[C[v]];
	ord[pos]--;
	C[v]--;
	if(L[C[v]]==R[C[v]]) {
		L[C[v]]=pos;
		R[C[v]]=pos+1;
	}
	else {
		L[C[v]]=pos;
	}
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	FOR(i,N) cin>>A[i];
	FOR(i,M) {
		cin>>j;
		if(j==1) {
			cin>>l>>r>>x;
			l--,r--;
			int tim=101010*(update.size()/DI*100 + l/DI);
			if(l/DI%2==0) tim+=r;
			else tim+=100010-r;
			event.push_back({tim,l,r,x,(int)update.size(),(int)event.size()});
		}
		else {
			cin>>x>>y;
			x--;
			update.push_back({x,A[x],y});
			A[x]=y;
		}
	}
	//
	for(i=update.size()-1;i>=0;i--) A[update[i][0]]=update[i][1];
	L[0]=0;
	R[0]=N;
	sort(ALL(event));
	int CL=0,CR=-1,CT=0;
	FORR(e,event) {
		int TL=e[1];
		int TR=e[2];
		int K=e[3];
		int TT=e[4];
		int& r=ret[e[5]];
		r=1<<20;
		while(CT<TT) {
			x=update[CT][0];
			if(x>=CL&&x<=CR) del(A[x]);
			A[x]=update[CT][2];
			if(x>=CL&&x<=CR) inc(A[x]);
			CT++;
		}
		while(CT>TT) {
			CT--;
			x=update[CT][0];
			if(x>=CL&&x<=CR) del(A[x]);
			A[x]=update[CT][1];
			if(x>=CL&&x<=CR) inc(A[x]);
		}
		while(TL<CL) inc(A[--CL]);
		while(CR<TR) inc(A[++CR]);
		while(CL<TL) del(A[CL++]);
		while(TR<CR) del(A[CR--]);
		
		int cur=0;
		while(ord[cur]) {
			if(ord[cur+(K-1)]) r=min(r,ord[cur]-ord[cur+(K-1)]);
			cur=R[ord[cur]];
		}
		if(r==1<<20) r=-1;
	}
	FOR(i,event.size()) cout<<ret[i]<<endl;
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}