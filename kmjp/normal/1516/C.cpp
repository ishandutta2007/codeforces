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

int N,A[2020];
bitset<2000*101> B;
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N;
	int g=0;
	FOR(i,N) {
		cin>>A[i];
		g=__gcd(g,A[i]);
	}
	int sum=0;
	B[0]=1;
	FOR(i,N) {
		A[i]/=g;
		sum+=A[i];
		B|=B<<A[i];
	}
	if(sum%2==0&&B[sum/2]) {
		cout<<1<<endl;
		FOR(i,N) if(A[i]%2==1) {
			cout<<(i+1)<<endl;
			break;
		}
	}
	else {
		cout<<0<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}