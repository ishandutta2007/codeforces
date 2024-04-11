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
int C[2020][2020];

int L[2020],R[2020];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		
		FOR(i,N) {
			cin>>s;
			FOR(j,N-i) C[i][i+j]=s[j]=='1';
			L[i]=R[i]=i;
		}
		vector<pair<int,int>> V;
		for(int len=1;len<=N;len++) {
			for(x=0;x+len<N;x++) {
				y=x+len;
				if(C[x][y]==0||L[x]==L[y]) continue;
				int X=x;
				int Y=y;
				V.push_back({x,y});
				int t=R[x]+1;
				int turn=1;
				while(t<L[y]) {
					if(turn) {
						V.push_back({t,Y});
						Y=t;
					}
					else {
						V.push_back({t,X});
						X=t;
					}
					turn^=1;
					t=R[t]+1;
				}
				
				
				int a=L[x];
				int b=R[y];
				for(j=a;j<=b;j++) L[j]=a, R[j]=b;
				
			}
		}
		assert(V.size()==N-1);
		FORR2(a,b,V) cout<<a+1<<" "<<b+1<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}