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

int R[10101];//={1,6,4,2,3,5,4};
int A[10101];//={1,6,4,2,3,5,4};
int AO[3][3];
int AA[3][3];

int askor(int i,int j) {
	if(R[0]) {
		return R[i]|R[j];
	}
	cout<<"or "<<(i+1)<<" "<<(j+1)<<endl;
	cin>>i;
	return i;
}

int askand(int i,int j) {
	if(R[0]) {
		return R[i]&R[j];
	}
	cout<<"and "<<(i+1)<<" "<<(j+1)<<endl;
	cin>>i;
	return i;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>K;
	FOR(x,3) FOR(y,x) {
		AO[x][y]=AO[y][x]=askor(x,y);
		AA[x][y]=AA[y][x]=askand(x,y);
	}
	FOR(i,30) {
		int o01=(AO[0][1]>>i)&1;
		int o12=(AO[1][2]>>i)&1;
		int o02=(AO[0][2]>>i)&1;
		int a01=(AA[0][1]>>i)&1;
		int a12=(AA[1][2]>>i)&1;
		int a02=(AA[0][2]>>i)&1;
		
		if(a01) A[0]|=1<<i,A[1]|=1<<i;
		if(a12) A[1]|=1<<i,A[2]|=1<<i;
		if(a02) A[0]|=1<<i,A[2]|=1<<i;
		if(o01+o12+o02==2) {
			if(o01+o12==2) A[1]|=1<<i;
			if(o01+o02==2) A[0]|=1<<i;
			if(o02+o12==2) A[2]|=1<<i;
		}
	}
	for(i=3;i<N;i++) {
		x=askor(0,i);
		y=askand(0,i);
		FOR(j,30) {
			if(y&(1<<j)) A[i]|=1<<j;
			else if((A[0]&(1<<j))==0 && (x&(1<<j))) A[i]|=1<<j;
		}
	}
	sort(A,A+N);
	cout<<"finish "<<A[K-1]<<endl;
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}