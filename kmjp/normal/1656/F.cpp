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


int T,N;
ll A[201010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		ll sum=0;
		FOR(i,N) {
			cin>>A[i];
			sum+=A[i];
		}
		sort(A,A+N);
		
		if(A[N-1]*(N-2)+sum<0) {
			cout<<"INF"<<endl;
			continue;
		}
		if(A[0]*(N-2)+sum>0) {
			cout<<"INF"<<endl;
			continue;
		}
		ll s=A[N-1]*(N-2)+sum;
		ll v=-(N-1)*A[N-1]*A[N-1];
		ll ret=v;
		
		for(i=N-1;i>=1;i--) {
			v+=s*(A[i]-A[i-1]);
			ret=max(ret,v);
			s+=A[0]-A[N-1];
		}
		cout<<ret<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}