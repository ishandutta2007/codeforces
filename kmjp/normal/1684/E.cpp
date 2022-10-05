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

int T,N,K;
int A[101010];
set<int> S[101010];
void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>K;
		map<int,int> M;
		FOR(i,N) {
			S[i+1].clear();
			cin>>x;
			M[x]++;
		}
		
		if(K>=N) {
			cout<<0<<endl;
			continue;
		}
		
		set<pair<int,int>> A,B;
		FORR2(a,b,M) B.insert({b,a});
		
		int ret=N;
		
		int sum=0;
		int can=0;
		FOR(i,N+2) if(can<=K) {
			if(M[i]==0) {
				while(sum>can) {
					auto p=*A.rbegin();
					A.erase(p);
					B.insert(p);
					sum-=p.first;
				}
				while(B.size()&&sum+B.begin()->first<=can) {
					auto p=*B.begin();
					A.insert(p);
					B.erase(p);
					sum+=p.first;
				}
				ret=min(ret,(int)B.size());
				
				can++;
			}
			else {
				
				if(A.count({M[i],i})) {
					A.erase({M[i],i});
					sum-=M[i];
					while(B.size()&&sum+B.begin()->first<=can) {
						auto p=*B.begin();
						A.insert(p);
						B.erase(p);
						sum+=p.first;
					}
				}
				else {
					B.erase({M[i],i});
				}
			}
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