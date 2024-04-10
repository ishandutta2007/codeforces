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

int T,N,M;
deque<int> B[101];


void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>M;
		vector<int> R[101];
		FOR(y,N) {
			FOR(x,M) {
				cin>>r;
				B[y].push_back(r);
			}
			sort(ALL(B[y]));
		}
		FOR(i,M) {
			int ma=1<<30,ind=-1;
			FOR(x,N) if(B[x][0]<ma) ma=B[x][0], ind=x;
			
			FOR(x,N) {
				if(x==ind) {
					R[x].push_back(B[x][0]);
					B[x].pop_front();
				}
				else {
					R[x].push_back(B[x].back());
					B[x].pop_back();
				}
			}
		}
		
		FOR(y,N) {
			FORR(x,R[y]) cout<<x<<" ";
			cout<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}