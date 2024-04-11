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

int N,P;
ll A[202020];
const ll mo=1000000007;

const int MAT=3;
struct Mat { ll v[MAT][MAT]; Mat(){ZERO(v);};};

Mat mulmat(Mat& a,Mat& b,int n=MAT) {
	ll mo2=4*mo*mo;
	int x,y,z; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(x,n) FOR(z,n) FOR(y,n) {
		r.v[x][y] += a.v[x][z]*b.v[z][y];
		if(r.v[x][y]>mo2) r.v[x][y] -= mo2;
	}
	FOR(x,n) FOR(y,n) r.v[x][y]%=mo;
	return r;
}

Mat powmat(ll p,Mat a,int n=MAT) {
	int i,x,y; Mat r;
	FOR(x,n) FOR(y,n) r.v[x][y]=0;
	FOR(i,n) r.v[i][i]=1;
	while(p) {
		if(p%2) r=mulmat(r,a,n);
		a=mulmat(a,a,n);
		p>>=1;
	}
	return r;
}


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>P;
	set<int> S;
	FOR(i,N) {
		cin>>A[i];
		S.insert(A[i]);
	}
	FOR(i,N) {
		x=A[i];
		while(x) {
			if(S.count(x)&&x!=A[i]) {
				S.erase(A[i]);
				break;
			}
			if(x%2==1) {
				x=x/2;
			}
			else if(x%4==0) {
				x/=4;
			}
			else {
				break;
			}
		}
	}
	
	
	Mat A;
	A.v[0][0]=A.v[0][1]=A.v[0][2]=1;
	A.v[1][1]=A.v[1][2]=1;
	A.v[2][1]=1;
	
	ll ret=0;
	FORR(a,S) {
		x=0;
		while((1<<x)<=a) x++;
		if(x<=P) {
			Mat B=powmat(P-x,A);
			ret+=B.v[0][1]+B.v[0][0];
		}
	}
	cout<<ret%mo<<endl;
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}