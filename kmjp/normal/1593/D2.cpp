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
int N;
vector<int> V[2020202];

int A[40],B[40];
int C[2020202];

void solve() {
	int i,j,k,l,r,x,y; string s;
	
	cin>>T;
	while(T--) {
		cin>>N;
		FOR(i,N) {
			cin>>A[i];
		}
		int ma=0;
		FOR(i,N) {
			map<int,int> from;
			from[0]=1;
			for(j=i+1;j<N;j++) {
				map<int,int> to;
				FORR2(a,b,from) {
					k=__gcd(a,abs(A[j]-A[i]));
					if(b+1==N/2) {
						if(k==0) ma=2000001;
						else ma=max(ma,k);
					}
					else {
						to[k]=max(to[k],b+1);
					}
				}
				FORR2(a,b,from) {
					to[a]=max(to[a],b);
				}
				swap(from,to);
			}
		}
		
		
		if(ma==2000001) ma=-1;
		cout<<ma<<endl;
	}
}


int main(int argc,char** argv){
	string s;int i;
	if(argc==1) ios::sync_with_stdio(false), cin.tie(0);
	FOR(i,argc-1) s+=argv[i+1],s+='\n'; FOR(i,s.size()) ungetc(s[s.size()-1-i],stdin);
	cout.tie(0); solve(); return 0;
}