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

int N;
int A[101010];
int M;

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>N>>M;
	ll sum=0;
	FOR(i,N) {
		cin>>A[i];
		sum+=i+1;
		if(i&&A[i]!=A[i-1]) {
			sum+=1LL*i*(N-i);
		}
	}
	
	while(M--) {
		cin>>i>>x;
		i--;
		if(i&&A[i]!=A[i-1]) sum-=1LL*i*(N-i);
		if(i<N-1&&A[i+1]!=A[i]) sum-=1LL*(i+1)*(N-i-1);
		A[i]=x;
		if(i&&A[i]!=A[i-1]) sum+=1LL*i*(N-i);
		if(i<N-1&&A[i+1]!=A[i]) sum+=1LL*(i+1)*(N-i-1);
		cout<<sum<<endl;
	}
	
	
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}