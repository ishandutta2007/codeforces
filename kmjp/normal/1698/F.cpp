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
int A[555],B[555];
vector<pair<int,int>> O;
void go(int L,int R) {
	assert(A[L]==A[R]);
	reverse(A+L,A+R+1);
	/*
	cout<<L<<" "<<R<<" ";
	int i;
	FOR(i,N) cout<<A[i];
	cout<<" ";
	FOR(i,N) cout<<B[i];
	cout<<endl;
	*/
	O.push_back({L+1,R+1});
}

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		multiset<pair<int,int>> X,Y;
		FOR(i,N) cin>>A[i];
		FOR(i,N) cin>>B[i];
		FOR(i,N-1) {
			X.insert({min(A[i],A[i+1]),max(A[i],A[i+1])});
			Y.insert({min(B[i],B[i+1]),max(B[i],B[i+1])});
		}
		if(X!=Y||A[0]!=B[0]||A[N-1]!=B[N-1]) {
			cout<<"No"<<endl;
			continue;
		}
		O.clear();
		FOR(i,N) if(A[i]!=B[i]) {
			retry:
			if(A[i]==B[i]) continue;
			for(j=i+1;j<N;j++) if(A[j]==B[i]) {
				if(j<N-1&&A[j+1]==A[i-1]) {
					go(i-1,j+1);
					break;
				}
			}
			if(A[i]==B[i]) continue;
			for(j=i+1;j<N;j++) if(A[j]==B[i]) {
				if(A[j-1]==A[i-1]) {
					for(x=i;x<j;x++) {
						for(y=j;y<N;y++) if(A[x]==A[y]) {
							go(x,y);
							goto retry;
						}
					}
					assert(0);
				}
			}
		}
		FOR(i,N) assert(A[i]==B[i]);
		cout<<"Yes"<<endl;
		cout<<O.size()<<endl;
		FORR2(a,b,O) cout<<a<<" "<<b<<endl;
		
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}