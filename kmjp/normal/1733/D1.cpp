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

int T,N,X,Y;
string A,B;

ll from[3030][2];
ll to[3030][2];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N>>X>>Y>>A>>B;
		FOR(x,N+2) from[x][0]=from[x][1]=1LL<<60;
		from[0][0]=0;
		int sum=0;
		vector<int> V;
		FOR(i,N) {
			k=A[i]!=B[i];
			if(k) V.push_back(i);
			sum+=k;
			if(k==0) {
				FOR(x,N+2) {
					from[x][0]=min(from[x][0],from[x][1]);
					from[x][1]=1LL<<60;
				}
			}
			else {
				FOR(x,N+2) {
					to[x][0]=to[x][1]=1LL<<60;
				}
				FOR(x,N+2) {
					// add
					to[x+1][1]=min(to[x+1][1],from[x][0]);
					to[x+1][1]=min(to[x+1][1],from[x][1]);
					//
					to[x][0]=min(to[x][0],from[x][0]+Y);
					to[x][0]=min(to[x][0],from[x][1]+Y);
					if(x) {
						// del
						to[x-1][0]=min(to[x-1][0],from[x][1]+X);
						to[x-1][0]=min(to[x-1][0],from[x][0]+Y);
					}
				}
				swap(from,to);
			}
		}
		
		if(V.size()%2) {
			cout<<-1<<endl;
		}
		else if(V.empty()) {
			cout<<0<<endl;
		}
		else if(V.size()==2) {
			if(V[0]+1==V[1]) {
				cout<<min(X,2*Y)<<endl;
			}
			else {
				cout<<Y<<endl;
			}
		}
		else {
			cout<<V.size()/2*Y<<endl;
		}
		
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}