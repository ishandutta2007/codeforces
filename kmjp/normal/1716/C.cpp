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
int A[2][202020];
int mau[2][202020];
int mad[2][202020];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[0][i];
			if(i) A[0][i]++;
		}
		FOR(i,N) {
			cin>>A[1][i];
			A[1][i]++;
		}
		FOR(i,2) {
			mau[i][N]=mad[i][N]=-1<<30;
			for(j=N-1;j>=0;j--) {
				mau[i][j]=max(mau[i][j+1]-1,A[i][j]);
				mad[i][j]=max(mad[i][j+1]+1,A[i][j]);
			}
		}
		int ret=1LL<<30;
		int sum=0;
		int step=0;
		int ma=0;
		FOR(i,N) {
			ma=max(ma,A[step][i]-sum);
			ret=min(ret,max({ma,mau[step][i]-sum,mad[step^1][i]-(sum+2*(N-1-i)+1)}));
			step^=1;
			sum++;
			
			ma=max(ma,A[step][i]-sum);
			ret=min(ret,max({ma,mau[step][i]-sum,mad[step^1][i+1]-(sum+2*(N-1-i))}));
			sum++;
		}
		
		ret=max(ret,0);
		cout<<(2*N-1)+ret<<endl;
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}