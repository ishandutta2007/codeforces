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

int T;
int N,M;
int P[303030];
int Q[303030];
int R[303030];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		map<int,int> dif;
		FOR(i,N) {
			cin>>P[i];
			P[i]--;
			x=(i-P[i]+N)%N;
			dif[x]++;
		}
		vector<int> ret;
		FORR2(a,b,dif) if(N-b<=2*M) {
			FOR(i,N) {
				Q[i]=P[(i+a)%N];
				R[Q[i]]=i;
			}
			int step=0;
			FOR(i,N) if(Q[i]!=i) {
				step++;
				x=R[i];
				swap(Q[i],Q[x]);
				R[Q[i]]=i;
				R[Q[x]]=x;
			}
			if(step<=M) ret.push_back(a);
			
		}
		
		cout<<ret.size();
		FORR(r,ret) cout<<" "<<r;
		cout<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}