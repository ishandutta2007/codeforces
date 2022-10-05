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
int A[101010];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		map<int,int> M;
		FOR(i,N) {
			cin>>A[i];
			M[A[i]]++;
		}
		int ng=0;
		FORR(m,M) if(m.second>(N+1)/2) ng=1;
		if(ng) {
			cout<<-1<<endl;
			continue;
		}
		M.clear();
		int sum=0;
		FOR(i,N-1) {
			if(A[i]==A[i+1]) {
				sum++;
				M[A[i]]++;
			}
		}
		int la=-1;
		FORR(m,M) if(m.second*2>sum) la=m.first;
		
		if(la==-1) {
			cout<<sum<<endl;
			continue;
		}
		int ret=0;
		int lef=sum-M[la];
		ret=2*lef;
		x=sum-2*lef;
		
		if(x&&A[0]!=la) ret++, x--;
		if(x&&A[N-1]!=la) ret++, x--;
		ret+=x*2;
		cout<<ret<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}