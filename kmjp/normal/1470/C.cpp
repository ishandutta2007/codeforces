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

int N,K;
int P=-1;

int A[101010];
int B[101010];
int C[101010];

void turn() {
	int i;
	FOR(i,N) B[i]=0;
	FOR(i,N) {
		if(i==P-1) {
			B[(i+1)%N]+=A[i];
		}
		else {
			B[(i+N-1)%N]+=A[i]/2;
			B[(i+1)%N]+=(A[i]+1)/2;
		}
	}
	FOR(i,N) A[i]=B[i];
}


int ask(int q) {
	int num;
	q=q%N;
	if(P==-1) {
		cout<<"? "<<(q+1)<<endl;
		cin>>num;
	}
	else {
		num=A[q];
		turn();
	}
	return num;
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(i,N) A[i]=K;
	
	FOR(i,350) ask(0);
	FOR(i,350) {
		C[i*N/350]=ask(i*N/350);
	}
	
	int ma=0,mai=0;
	int mi=K+1,mii=0;
	FOR(i,N) {
		if(C[i]>ma) ma=C[i],mai=i;
		if(C[i]>0&&C[i]<mi) mi=C[i],mii=i;
	}
	if(mai<mii) mai+=N;
	
	if(mii+200<mai) {
		x=ask((mai+mii)/2);
		if(x>=ma) mai=(mai+mii)/2;
		else mii=(mai+mii)/2-1;
	}
	
	for(i=mai;i>=mii;i--) {
		if(ask(i)==K) {
			cout<<"! "<<(i%N+1)<<endl;
			break;
		}
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}